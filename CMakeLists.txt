cmake_minimum_required(VERSION 3.18)
project(AviSynthCUDAFilters LANGUAGES CXX CUDA)

find_package(CUDAToolkit REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVISYNTH REQUIRED avisynth)
pkg_check_modules(GTEST REQUIRED gtest)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -mtune=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -mtune=native")
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xcompiler -march=native,-mtune=native")
# set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON) # Conflict with Visual Studio Code Intellisense on CUDA
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_SEPARABLE_COMPILATION ON)
set(CMAKE_CUDA_ARCHITECTURES native)

add_subdirectory(AvsCUDA)
add_subdirectory(KDebugTool)
add_subdirectory(KTGMC)
add_subdirectory(KFM)
add_subdirectory(KUtil)
add_subdirectory(KTGMCTest)
