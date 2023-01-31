#include "../common/common_public.h"
#include "core/core.h"
#include "r_public.h"

#include <SDL3/SDL_vulkan.h>
#include <glad/vulkan.h>

cvar_t r_cvars[] = {{"r_physicalDeviceIndex", "0", CVAR_NUMBER | CVAR_STATIC}};

static SDL_Window *S_Window = NULL;

const char *requested_instance_layers[] = {"VK_LAYER_KHRONOS_validation", NULL};

bool checkValidationSupport();

void R_Preinit()
{
        CVar_Register(arraysize(r_cvars), r_cvars);
}

void R_Init()
{
        CVAR(r_physicalDeviceIndex);
        CVAR(com_windowWidth);
        CVAR(com_windowHeight);
        CVAR(com_fullscreen);

#ifdef _DEBUG
        const bool enabledValidationLayers = true;
#else
        const bool enabledValidationLayers = false;
#endif

        S_Window = SDL_CreateWindow("", 100, 100, 100, 100,
                                    SDL_WINDOW_VULKAN | SDL_WINDOW_HIDDEN);

        gladLoadVulkan(NULL, SDL_Vulkan_GetVkGetInstanceProcAddr());

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

void R_Shutdown()
{
}
void R_ResetSwapChain()
{
}

bool checkValidationSupport()
{
}
