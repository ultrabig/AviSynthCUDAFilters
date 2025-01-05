project(KTGMCTest LANGUAGES CXX CUDA)

add_executable(${PROJECT_NAME}
    KTGMCTest.cpp
    TestMain.cpp
    MaskToolsTest.cpp
    TestCommons.cpp
    AvsCUDATest.cpp
    MiscTest.cpp
    KFMTest.cpp
    TestCommons.h
)

# AVS_Linkage won't work with this
# target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${AVISYNTH_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${GTEST_CFLAGS_OTHER})

target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
