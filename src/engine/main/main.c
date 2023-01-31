#include "core/core.h"
#include "common/common_public.h"

#ifdef COMPILER_CL
__declspec(noreturn)
#endif
int main(int argc, char* argv[])
{
    Common_Init();    

    while (1) {
        Common_Frame();
    }
}