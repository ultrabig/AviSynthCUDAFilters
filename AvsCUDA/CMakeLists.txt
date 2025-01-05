project(AvsCUDA LANGUAGES CXX CUDA)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_SOURCE_DIR}/common/Copy.h
    AvsCUDA.h
    AvsCUDAversion.h
    filters/convert_avx.h
    filters/convert_avx2.h
    filters/focus.h
    filters/merge.h
    filters/merge_avx2.h
    filters/resample.h
    filters/resample_avx2.h
    filters/resample_functions.h
    ${CMAKE_SOURCE_DIR}/common/DeviceLocalData.cpp
    AvsCUDA.cpp
    filters/convert_avx.cpp
    filters/convert_avx2.cpp
    filters/focus.cpp
    filters/focus_avx2.cpp
    filters/turn.cpp
    ${CMAKE_SOURCE_DIR}/common/Copy.cu
    filters/Convert.cu
    filters/merge.cu
    filters/merge_avx2.cpp
    filters/resample_avx2.cpp
    filters/resample_functions.cpp
    filters/SupportFilters.cpp
    filters/resample.cu
    filters/ConditionalFunctions.cu
    filters/Filters.cu
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/common)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
