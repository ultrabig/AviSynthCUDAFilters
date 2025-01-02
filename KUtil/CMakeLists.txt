project(KUtil LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED KUtil.cpp)

target_link_libraries(${PROJECT_NAME} ${AVISYNTH_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${AVISYNTH_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${AVISYNTH_CFLAGS_OTHER})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/common)
