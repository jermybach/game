#ifndef DEBUG_H
#define DEBUG_H

enum {
    LOG_DEBUG,
    LOG_TRACE,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
};

void Debug_LogMessage(int priority, const char* filename, int line, const char* fmt, ...);

#define DDebug(...) Debug_LogMessage(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define DTrace(...) Debug_LogMessage(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define DWarn(...)  Debug_LogMessage(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define DError(...) Debug_LogMessage(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define DFatal(...) Debug_LogMessage(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

#define DFatalIf(cond)     \
    do {                   \
        if (cond) {        \
            DFatal(#cond); \
        }                  \
    } while(0)

#endif//DEBUG_H