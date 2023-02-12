#include "core/core.h"
#include "win32_local.h"
#include "common/common_public.h"
#include "sys/sys_public.h"

#ifdef _WIN32

#include <Windows.h>

sysInfo_t sysInfo;

INT WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow
) {
    Common_Preinit();
    
    Common_Init();

    while (Common_Running()) {
        Common_Frame();
    }

    Common_Shutdown();

    return 0;
}

void Sys_PumpEvents()
{
    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

#endif