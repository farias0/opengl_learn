cmake_minimum_required(VERSION 3.16)

project(opengl_learn)


find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw-3.4)

add_subdirectory(external/glm)

add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include)


add_executable(${PROJECT_NAME} src/main.cpp external/stb/stb_image.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL glad glm::glm-header-only)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/stb)


if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
endif()
