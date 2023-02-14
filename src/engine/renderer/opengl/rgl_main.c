/**
 * @file rgl_main.c
 * @author JAB
 * @date Feb 12 2023
 * 
 * @brief Implements most of the OpenGL driver
 */
#include "core/core.h"
#include "common/common_public.h"
#include "config.h"
#include "renderer/r_public.h"
#include "sys/sys_public.h"
#ifdef RENDERER_ENABLE_OPENGL
#include <glad/gl.h>

#if COMPILER_CL
#pragma comment(lib, "opengl32.lib")
#endif

void RGL_Preinit() {}
void RGL_Init() {
    gladLoadGL((GLADloadfunc)Sys_GL_GetProcAddr);

}
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