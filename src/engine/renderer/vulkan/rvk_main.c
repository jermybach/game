#include "common/common_public.h"
#include "core/core.h"
#include "renderer/r_public.h"
#include "config.h"

#ifdef RENDERER_ENABLE_VULKAN
#include <glad/vulkan.h>

cvar_t r_cvars[] = {
        {"r_physicalDeviceIndex", "0", CVAR_NUMBER | CVAR_STATIC},
        };

const char *requested_instance_layers[] = {"VK_LAYER_KHRONOS_validation", NULL};

bool checkValidationSupport();

void RVK_Preinit()
{
        CVar_Register(arraysize(r_cvars), r_cvars);
}

void RVK_Init()
{
        DTrace("RVK_Init() -- Initializing Vulkan renderer");
        CVAR(r_physicalDeviceIndex);
        CVAR(com_windowWidth);
        CVAR(com_windowHeight);
        CVAR(com_fullscreen);

#ifdef _DEBUG
        const bool enabledValidationLayers = true;
#else
        const bool enabledValidationLayers = false;
#endif

        VkApplicationInfo app_info = {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .apiVersion = VK_API_VERSION_1_2,
            .applicationVersion = 0x00000001,
            .engineVersion = 0x00000001,
            .pApplicationName = "game",
            .pEngineName = "game",
            .pNext = NULL,
        };

        VkInstanceCreateInfo instance_ci = {.pApplicationInfo = &app_info,
};
}

void RVK_Shutdown()
{
}

void RVK_BeginFrame()
{
}

void RVK_EndFrame()
{
}

void RVK_ResetSwapChain()
{
}

bool checkValidationSupport()
{
}

renderInterface_t rvk_interface = {
        .R_Preinit = RVK_Preinit,
        .R_Init = RVK_Init,
        .R_Shutdown = RVK_Shutdown,
        .R_BeginFrame = RVK_BeginFrame,
        .R_EndFrame = RVK_EndFrame,
};
// TODO: Move rapi to some kind of pre-init driver select function in a renderer/r_*.c file
renderInterface_t *rapi = &rvk_interface;

#endif
