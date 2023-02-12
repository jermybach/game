#ifndef RENDERER_PUBLIC_H
#define RENDERER_PUBLIC_H

typedef struct renderInterface_t renderInterface_t;
struct renderInterface_t {
    void(*R_Preinit)();
    void(*R_Init)();
    void(*R_Shutdown)();
    void(*R_BeginFrame)();
    void(*R_EndFrame)();
};

extern renderInterface_t *rapi;

//
// Wrappers
//

inline void R_Preinit() { rapi->R_Preinit(); }
inline void R_Init() { rapi->R_Init(); }
inline void R_Shutdown() { rapi->R_Shutdown(); }
inline void R_BeginFrame() { rapi->R_BeginFrame(); }
inline void R_EndFrame() { rapi->R_EndFrame(); }



#endif//RENDERER_PUBLIC_H