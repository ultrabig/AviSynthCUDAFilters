#define _CRT_SECURE_NO_WARNINGS
#include "avisynth.h"

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

#include "CommonFunctions.h"
#include "DeviceLocalData.h"
#include "DebugWriter.h"
#include "Misc.h"

#include <string>
#include <thread>
#include <iostream>

// commonのcppを取り入れる
#include "DebugWriter.cpp"
#include "DeviceLocalData.cpp"

void AddFuncKernel(IScriptEnvironment* env);
void AddFuncMV(IScriptEnvironment* env);

static void init_console()
{
#ifdef _WIN32
  AllocConsole();
  freopen("CONOUT$", "w", stdout);
  freopen("CONIN$", "r", stdin);
#endif
}

void OnCudaError(cudaError_t err) {
#if 1 // デバッグ用（本番は取り除く）
  printf("[CUDA Error] %s (code: %d)\n", cudaGetErrorString(err), err);
#endif
}

int GetDeviceTypes(const PClip& clip)
{
  int devtypes = (clip->GetVersion() >= 5) ? clip->SetCacheHints(CACHE_GET_DEV_TYPE, 0) : 0;
  if (devtypes == 0) {
    return DEV_TYPE_CPU;
  }
  return devtypes;
}

// Timer class using std::chrono for cross-platform compatibility.
class Timer {
  std::chrono::high_resolution_clock::time_point start_time;

public:
  Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

  double elapsed_seconds() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end_time - start_time).count();
  }
};

class Time : public GenericVideoFilter {
  std::string name;
public:
  Time(PClip _child, const char* name, IScriptEnvironment* env)
    : GenericVideoFilter(_child)
    , name(name)
  { }

  PVideoFrame __stdcall GetFrame(int n, IScriptEnvironment* env)
  {
    Timer timer;

    PVideoFrame frame = child->GetFrame(n, env);

    double elapsed = timer.elapsed_seconds();
    auto thread_id = std::this_thread::get_id();

    std::cout << "[" << thread_id << "] N:" << n 
              << " " << name << ": " << elapsed * 1000 << " ms\n";

    return frame;
  }
};

AVSValue __cdecl Create_Time(AVSValue args, void* user_data, IScriptEnvironment* env) {
  return new Time(args[0].AsClip(), args[1].AsString("Time"), env);
}

const AVS_Linkage *AVS_linkage = 0;

extern "C" __declspec(dllexport) const char* __stdcall AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors)
{
  AVS_linkage = vectors;
  //init_console();

  AddFuncKernel(env);
  AddFuncMV(env);

  return "CUDA Accelerated QTGMC Plugin";
}
