add_library(core STATIC)
target_precompile_headers(core PRIVATE "core.h")
EngineModuleDefaults(core)

target_sources(core PRIVATE
    "basetypes.h"
    "core.c"
    "core.h"
    "debug.c"
    "debug.h"
    "math/minmax.h"
    "memory.h"
    "threads.h"
    "win32/win32_private.h"
    "win32/win32_threads.c"
    "win32/win32_winmain.c"
 "container/list.h" "strutils.h" "strutils.c")

if(WIN32)
target_link_libraries(core PUBLIC dirent)
endif()