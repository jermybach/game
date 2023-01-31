/**
 * @file common/extension.h
 * The extension api provides an interface to interact with engine code/functions from shared libraries.
*/
#ifndef EXTENSION_H
#define EXTENSION_H
#include "common_public.h"

typedef struct {
    int version;
    cvar_t *(CVar_Get)(const char*);
    void (*CVar_SetValue)(cvar_t *, const char *);
    void (*CVar_Register)(size_t, cvar_t *);
} extension_imports_t;

extern extension_imports_t extension_imports;

#endif//EXTENSION_H
