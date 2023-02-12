set(EXE_NAME "client_amd64")
add_executable(${EXE_NAME})
target_link_libraries(${EXE_NAME}
PRIVATE 
    core
    glad
)
if(WIN32)
target_link_libraries(${EXE_NAME} PRIVATE )    
endif()
target_include_directories(${EXE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}")
target_sources(${EXE_NAME}
PUBLIC
    "common/common_main.c"
    "common/common_public.h"
    "common/cvar.c"
    "common/extension.h"
    "main/main.c"
    "renderer/r_public.h"
    "renderer/vulkan/rvk_main.c"
    "sys/sys_public.h"
    "sys/win32/win32_local.h"
    "sys/win32/win32_misc.c"
    "sys/win32/win32_winmain.c"
    "renderer/opengl/rgl_main.c"
    )
