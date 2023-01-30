set(EXE_NAME "client_amd64")
add_executable(${EXE_NAME})
target_include_directories(${EXE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(${EXE_NAME}
PUBLIC
    "common/common_main.c"
    "common/common_public.h"
    "common/extension.h"
    "renderer/renderer_public.h"
    "sys/sdl/sdl_local.h"
    "sys/sdl/sdl_main.c"
    "sys/sys_public.h"
    "sys/win32/win32_misc.c"
)
