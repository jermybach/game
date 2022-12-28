set(EXE_NAME "client_amd64")
add_executable(${EXE_NAME} 
PUBLIC
    "common/extension.h"
    "renderer/renderer_public.h"
    "sys/sdl/sdl_local.h"
    "sys/sys_public.h"
    "sys/sdl/sdl_main.c"
    "common/common_public.h"
    "common/common_main.c"
    "sys/win32/win32_misc.c"
)
