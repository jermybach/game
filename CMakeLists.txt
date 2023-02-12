cmake_minimum_required(VERSION 3.16)
project(LiteEngine VERSION 0.0.1 LANGUAGES C)

# Options
set(RENDERER_ENABLE_OPENGL ON CACHE BOOL "Enable OpenGL 3.3 core renderer implementation")
set(RENDERER_ENABLE_VULKAN OFF CACHE BOOL "Enable the vulkan renderer implementation (LunarG loader)")

# CMake settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_CUDA_STANDARD_REQUIRED YES)

# this fixes some compiler warning/errors
add_compile_definitions("MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS=0")

add_subdirectory(thirdparty)
add_subdirectory(src)
