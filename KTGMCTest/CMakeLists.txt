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

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${AVISYNTH_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${GTEST_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${GTEST_CFLAGS_OTHER})

target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_CUDA)

target_include_directories(${PROJECT_NAME} PUBLIC ${CUDAToolkit_INCLUDE_DIRS})
