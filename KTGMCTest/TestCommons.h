#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#define AVS_LINKAGE_DLLIMPORT
#endif
#include "avisynth.h"

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#else
#include <linux/limits.h>
#include <dlfcn.h>
#endif

#include <gtest/gtest.h>

#include <fstream>
#include <string>
#include <iostream>
#include <memory>
#include <filesystem>

#define O_C(n) ".OnCUDA(" #n ", 0)"

std::string GetDirectoryName(const std::string& filename);

#ifndef _WIN32

// https://github.com/AviSynth/AviSynthPlus/issues/130#issuecomment-595892327
class AVSLoader {
  void *handle = nullptr;
  // IScriptEnvironment2 *env = nullptr;
  public:
  AVSLoader() {
    handle = dlopen("libavisynth.so", RTLD_NOW | RTLD_LOCAL);
    if (handle == nullptr) {
      std::cerr << "Failed to load avisynth.so" << std::endl;
      return;
    }
  }
  // IScriptEnvironment2* get() {
    // return env;
  // }
  // IScriptEnvironment2* operator ->() {
    // return env;
  // }
  ~AVSLoader() {
    if (AVS_linkage != nullptr) {
      AVS_linkage = nullptr;
    }
    // if (env != nullptr) {
      // env->DeleteScriptEnvironment();
      // env = nullptr;
    // }
    if (handle != nullptr) {
      dlclose(handle);
      handle = nullptr;
    }
  }
  IScriptEnvironment2* CreateScriptEnvironment2() {
    void* mkr = dlsym(handle, "CreateScriptEnvironment2");
    if (mkr == nullptr) {
      std::cerr << "Failed to load CreateScriptEnvironment2" << std::endl;
      return nullptr;
    }
    typedef IScriptEnvironment2 * (*CreateScriptEnvironment2_t)(int);
    CreateScriptEnvironment2_t cse2 = reinterpret_cast<CreateScriptEnvironment2_t>(mkr);
    auto env = cse2(AVISYNTH_INTERFACE_VERSION);
    if (AVS_linkage == nullptr) {
      AVS_linkage = env->GetAVSLinkage();
    }
    return env;
  }
};

#endif

struct ScriptEnvironmentDeleter {
  void operator()(IScriptEnvironment* env) {
    env->DeleteScriptEnvironment();
  }
};

typedef std::unique_ptr<IScriptEnvironment2, ScriptEnvironmentDeleter> PEnv;

class AvsTestBase : public ::testing::Test {
protected:
  AvsTestBase() { }

  virtual ~AvsTestBase() {
    // テスト毎に実行される，例外を投げない clean-up をここに書きます．
  }

  // コンストラクタとデストラクタでは不十分な場合．
  // 以下のメソッドを定義することができます：

  virtual void SetUp() {
    // このコードは，コンストラクタの直後（各テストの直前）
    // に呼び出されます．
#ifdef _WIN32
    char buf[MAX_PATH];
    GetModuleFileName(nullptr, buf, MAX_PATH);
    modulePath = GetDirectoryName(buf);
    workDirPath = GetDirectoryName(GetDirectoryName(modulePath)) + "\\TestScripts";
#else
    char buf[PATH_MAX];
    readlink("/proc/self/exe", buf, PATH_MAX);
    modulePath = GetDirectoryName(buf);
    workDirPath = GetDirectoryName(GetDirectoryName(modulePath)) + "/TestScripts";
#endif
  }

  virtual void TearDown() {
    // このコードは，各テストの直後（デストラクタの直前）
    // に呼び出されます．
  }

  std::filesystem::path modulePath;
  std::filesystem::path workDirPath;

  enum TEST_FRAMES {
    TF_MID, TF_BEGIN, TF_END, TF_100
  };

  void GetFrames(PClip& clip, TEST_FRAMES tf, PNeoEnv env);
};

