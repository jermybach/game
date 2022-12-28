/**
 * @todo Replace the localtime stuff with core/time.h stuff
*/
#include "core.h"
#include "debug.h"

#if OS_WINDOWS
#include "win32/win32_private.h"
#endif

void Debug_LogMessage(int priority, const char* filename, int line, const char* fmt, ...)
{
    char buffer[512];
    memset(buffer, 0, 512);

    size_t written = 0;
    static const char* priority_texts[] = {
        "DEBUG",
        "TRACE",
        "WARN",
        "ERROR",
        "FATAL",
    };

    //time_t _time = time(NULL);
    //struct tm* _time_local = localtime(&_time);   

    //written = strftime(buffer, 512, "%H:%M:%S", _time_local);
    written += snprintf(buffer + written, 512 - written, " %s:%d %s ", filename, line, priority_texts[priority]);
    va_list ap;
    va_start(ap, fmt);
    /* size_t unwritten = */ vsnprintf(buffer, 512, fmt, ap);
    va_end(ap);

#if OS_WINDOWS
    OutputDebugStringA(buffer);
#endif

    if (priority == LOG_FATAL) {
#if OS_WINDOWS
        MessageBoxA(NULL, buffer, "Error", MB_ICONERROR);
#endif
        exit(1);
    }

}