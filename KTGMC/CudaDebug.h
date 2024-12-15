#pragma once

#ifdef _WIN32
#else
#include <stdio.h>
#endif

template <typename T>
class DataDebug
{
public:
  DataDebug(T* ptr, int size, PNeoEnv env) {
    host = (T*)malloc(sizeof(T)*size);
    CUDA_CHECK(cudaMemcpy(host, ptr, sizeof(T)*size, cudaMemcpyDeviceToHost));
    CUDA_CHECK(cudaDeviceSynchronize());
  }

  ~DataDebug() {
    free(host);
  }

  void  Show() {
    printf("!!!");
  }

  T* host;
};
