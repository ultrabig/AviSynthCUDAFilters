cmake_minimum_required(VERSION 3.18)
project(AviSynthCUDAFilters LANGUAGES CXX CUDA)

find_package(CUDAToolkit REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVISYNTH REQUIRED avisynth)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -mtune=native")
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -march=native -mtune=native")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)

add_subdirectory(AvsCUDA)
add_subdirectory(KDebugTool)
add_subdirectory(KTGMC)
add_subdirectory(KFM)
add_subdirectory(KUtil)
