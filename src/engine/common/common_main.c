#include "common_public.h"
#include "renderer/r_public.h"

cvar_t com_cvars[] = {
    {"com_fullscreen", "-1", CVAR_NUMBER, R_ResetSwapChain},
    {"com_windowWidth", "1280", CVAR_NUMBER},
    {"com_windowWidth", "720", CVAR_NUMBER},
};

void Common_Preinit()
{
    CVar_Register(arraysize(com_cvars), com_cvars);
    R_Preinit();
}

void Common_Init()
{
    DTrace("Common_Init()");
    
}

void Common_Shutdown()
{
    
}

void Common_Frame()
{
    
}

