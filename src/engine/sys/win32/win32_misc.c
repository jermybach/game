#include "core/core.h"
#include "win32_local.h"
#ifdef _WIN32

bool Sys_IsInstanceAlreadyRunning()
{
    return false;
}

void* Sys_GetVulkanLoaderFunc()
{
    
}

#endif
