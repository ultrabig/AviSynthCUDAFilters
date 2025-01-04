#define _CRT_SECURE_NO_WARNINGS

#define AVS_LINKAGE_DLLIMPORT
#include "avisynth.h"
#pragma comment(lib, "avisynth.lib")

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif

#include "gtest/gtest.h"

int main(int argc, char **argv)
{
  if (argc > 1) {
    ::testing::GTEST_FLAG(filter) = argv[1];
  } else {
    ::testing::GTEST_FLAG(filter) = "*.*";
  }
  ::testing::InitGoogleTest(&argc, argv);

  //_crtBreakAlloc = 7978;
  //_CrtMemState s1;
  //_CrtMemCheckpoint(&s1);

  int result = RUN_ALL_TESTS();

  //_CrtMemDumpAllObjectsSince(&s1);

  //getchar();

  return result;
}

