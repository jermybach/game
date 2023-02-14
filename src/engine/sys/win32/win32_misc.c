#include "core/core.h"
#include "win32_local.h"
#ifdef _WIN32

bool Sys_IsInstanceAlreadyRunning()
{
    return false;
}

void* Sys_GetVulkanLoaderFunc()
{
    
 return NULL;
}


#ifdef RENDERER_ENABLE_OPENGL
void *Sys_GL_GetProcAddr(const char* procname)
{
    uintptr_t ptr = (uintptr_t)wglGetProcAddress(procname);
    if (ptr == -1 || (ptr >= 0 && ptr <= 4)) {
        HANDLE hLib = LoadLibrary("opengl32.dll");
        DFatalIf(hLib == NULL);
        ptr = GetProcAddress(hLib, procname);
    }
    return (void*)ptr;
}

#endif

#endif
