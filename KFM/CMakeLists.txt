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

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/common)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
