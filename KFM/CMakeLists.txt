project(KFM LANGUAGES CXX CUDA)

add_library(${PROJECT_NAME} SHARED
    DeblockAVX.cpp
    KFM.cpp
    ${CMAKE_SOURCE_DIR}/common/Copy.cu
    Deblock.cu
    TextOut.cu
    ${CMAKE_SOURCE_DIR}/common/Copy.h
    KFM.h
    KFMFilterBase.cuh
    KFMversion.h
    SIMDSupport.hpp
    TextOut.h
    CombingAnalyze.cu
    DecombeUCF.cu
    KDeband.cu
    KFMFilterBase.cu
    KFMKernel.cu
    MergeStatic.cu
)

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/common)

set_target_properties(${PROJECT_NAME} PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PUBLIC ${CUDAToolkit_INCLUDE_DIRS})
