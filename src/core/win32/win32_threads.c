#include "../core.h"
#include "../threads.h"
#include "win32_private.h"

struct thread_t {
    HANDLE hThread;
    DWORD dwThreadId;
};
thread_t* thread_create(PFNTHREADENTRY entry, void* user_data)
{
    thread_t* thread = new(thread_t);
    thread->hThread = CreateThread(
        NULL, 
        0, 
        (LPTHREAD_START_ROUTINE)entry,
        user_data, 
        0,
        &(thread->dwThreadId)
    );
    return thread;
}

void thread_detach(thread_t* thread)
{
    CloseHandle(thread);
    free(thread);
}

struct mutex_t {
    CRITICAL_SECTION cs;
};

mutex_t* mutex_create()
{
    mutex_t* mutex = new(mutex_t);
    InitializeCriticalSection(&(mutex->cs));
    return mutex;
}

void mutex_delete(mutex_t* mutex)
{
    DeleteCriticalSection(&mutex->cs);
    free(mutex);
}

bool mutex_trylock(mutex_t* mutex)
{
    return (bool)TryEnterCriticalSection(&mutex->cs);
}

void mutex_unlock(mutex_t* mutex)
{
    LeaveCriticalSection(&(mutex->cs));
}

struct cond_t {
    CONDITION_VARIABLE conditional_variable;
};

cond_t* cond_create()
{
    cond_t* cond = new(cond_t);
    InitializeConditionVariable(&(cond->conditional_variable));
    return cond;
}

void cond_delete(cond_t* cond)
{
    free(cond);
}

void cond_wait(cond_t* cond, mutex_t *mutex)
{
    SleepConditionVariableCS(&cond->conditional_variable, &mutex->cs, INFINITE);
}

void cond_signal(cond_t* cond)
{
    WakeConditionVariable(&cond->conditional_variable);
}

void cond_broadcast(cond_t* cond)
{
    WakeAllConditionVariable(&cond->conditional_variable);
}

 