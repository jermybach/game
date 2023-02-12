#include "core/core.h"
#include "common_public.h"
#include "renderer/r_public.h"

cvar_t com_cvars[] = {
    {"com_fullscreen", "-1", CVAR_NUMBER,},
    {"com_windowWidth", "1280", CVAR_NUMBER},
    {"com_windowWidth", "720", CVAR_NUMBER},
};

bool Running = false;

void Common_Preinit()
{
    CVar_Register(arraysize(com_cvars), com_cvars);
    R_Preinit();
}

void Common_Init()
{
    DTrace("Common_Init()");
    
    Running = true;
}

void Common_Shutdown()
{
    
}

bool Common_Running() { return Running; }

void Common_Frame()
{
    Sys_PumpEvents();
}

