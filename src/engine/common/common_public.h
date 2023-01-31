#ifndef COMMON_PUBLIC_H
#define COMMON_PUBLIC_H
#include "core/core.h"

/* COMMON */

void Common_Init();
void Common_Shutdown();
void Common_Frame();

/* CVARS */
#define CVAR_VALUE_MAX 128

typedef enum {
    CVAR_STRING = BIT(0),
    CVAR_NUMBER = BIT(1),
    CVAR_STATIC = BIT(5),
    CVAR_RECORD = BIT(6),
    CVAR_ROM = BIT(7),
    CVAR_REPLICATE = BIT(8),
    CVAR_CLIENT = BIT(9),
    CVAR_SERVER = BIT(10),
    CVAR_CHEAT = BIT(11),
} cvarFlags_t;

typedef struct cvar_t  {
    const char* name;
    const char* defaultvalue;
    cvarFlags_t flags;
    void(*callback)(void);
    const char* description;
    float min;
    float max;

    char value[CVAR_VALUE_MAX];
    float numberValue;

    struct cvar_t *next;
} cvar_t;

cvar_t *CVar_Get(const char* name);
void CVar_Register(size_t count, cvar_t* cvars);
void CVar_SetValueQuiet(cvar_t* cvar, const char* value);
void CVar_SetValue(cvar_t* cvar, const char* value);

#define CVAR(name) cvar_t *name = CVar_Get(#name);

#endif//COMMON_PUBLIC_H
