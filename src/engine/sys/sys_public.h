#pragma once

void Sys_Init(void);
void Sys_Shutdown(void);

bool Sys_IsInstanceAlreadyRunning();

typedef struct socialIntegrationState_t socialIntegrationState_t;
struct socialIntegrationState_t {
    char title[100];
    char description[100];
    int partySize;
    int partyMax;
    int timeElapsed;
    int timeMax;
};

void Sys_UpdateSocial(const socialIntegrationState_t* social);
