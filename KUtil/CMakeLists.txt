project(KUtil LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED KUtil.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/common)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_CUDA)