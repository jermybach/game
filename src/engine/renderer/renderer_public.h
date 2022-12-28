#ifndef RENDERER_PUBLIC_H
#define RENDERER_PUBLIC_H

typedef struct {
    int version;
    void(*R_Init)();
    void(*R_Shutdown)();
    void(*R_Clear)();
    void(*R_SwapFrame)();
} renderer_exports_t;

typedef renderer_exports_t*(*PFNGETRENDERERIMPORTS)()

#endif//RENDERER_PUBLIC_H
