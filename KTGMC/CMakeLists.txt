project(KTGMC LANGUAGES CXX CUDA)

add_library(${PROJECT_NAME} SHARED
    CudaDebug.h
    CudaKernelBase.h
    GenericImageFunctions.cuh
    Kernel.cu
    Misc.cpp
    Misc.h
    MV.cpp
    MVKernel.cu
    MVKernel.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/common)

target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PUBLIC ${CUDAToolkit_INCLUDE_DIRS})
