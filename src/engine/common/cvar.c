#include "common_public.h"
#include "core/core.h"

#define CVAR_TABLE_SIZE 512

cvar_t *cvartable[CVAR_TABLE_SIZE];

void CVar_Init()
{
        memset(cvartable, 0, sizeof(cvartable));
}

cvar_t *CVar_Get(const char *name)
{
        uint32_t hash = core_hash32(name, strlen(name));
        cvar_t *test = cvartable[hash % CVAR_TABLE_SIZE];
        
        while (strcmp(name, test->name) != 0)
        {
                test = test->next;
                
                if (test == NULL)
                        return NULL;
        }
        return test;
}

void CVar_Register(size_t count, cvar_t *cvars)
{
        for (size_t i = 0; i < count; i++)
        {
                cvar_t *cvar = &cvars[i];
                uint32_t hash = core_hash32(cvar->name, strlen(cvar->name));

                cvar_t **t = &cvartable[hash % CVAR_TABLE_SIZE];
                do
                {
                        if (*t == NULL)
                        {
                                *t = cvar;
                                break;
                        }
                        else
                        {
                                t = &(*t)->next;
                        }
                } while (1);
        }
}

void CVar_SetValueQuiet(cvar_t *cvar, const char *value)
{
        size_t len = min(strlen(value) - 1, CVAR_VALUE_MAX - 1);
        memcpy(cvar->value, value, len);
        cvar->value[len] = '\0';
        cvar->numberValue = (float)atof(value);
}

void CVar_SetValue(cvar_t *cvar, const char *value)
{
        CVar_SetValueQuiet(cvar, value);
        if (cvar->callback)
                cvar->callback();
}
