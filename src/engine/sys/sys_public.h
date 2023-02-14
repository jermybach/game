#pragma once
#include "core/core.h"
#include "config.h"

typedef struct socialIntegrationState_t socialIntegrationState_t;
typedef struct sysInfo_t sysInfo_t;

void Sys_PumpEvents();
bool Sys_IsInstanceAlreadyRunning();
void Sys_UpdateSocial(const socialIntegrationState_t* social);
void* Sys_GetVulkanLoaderFunc();

#ifdef RENDERER_ENABLE_OPENGL
void *Sys_GL_GetProcAddr(const char* procname);
#endif

struct sysInfo_t{
    int cpu_count;
};

extern sysInfo_t sysInfo;

struct socialIntegrationState_t {
    const char* title;
    const char* description;
    int partySize;
    int partyMax;
    int timeElapsed;
    int timeMax;
};

