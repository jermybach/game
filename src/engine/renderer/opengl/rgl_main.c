/**
 * @file rgl_main.c
 * @author JAB
 * @date Feb 12 2023
 * 
 * @brief Implements most of the OpenGL driver
 */
#include "../r_public.h"
#include "core/core.h"
#include "common/common_public.h"
#include "config.h"
#ifdef RENDERER_ENABLE_OPENGL
#include <glad/gl.h>

void RGL_Preinit() {}
void RGL_Init() {}
void RGL_Shutdown() {}
void RGL_BeginFrame() {}
void RGL_EndFrame() {}

renderInterface_t rgl_interface = {
    .R_Preinit = RGL_Preinit,
    .R_Init = RGL_Init,
    .R_Shutdown = RGL_Shutdown,
    .R_BeginFrame = RGL_BeginFrame,
    .R_EndFrame = RGL_EndFrame,
};
renderInterface_t *rapi = &rgl_interface;

#endif