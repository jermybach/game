#ifndef THREADS_H
#define THREADS_H

typedef int(*PFNTHREADENTRY)(void*);
typedef struct thread_t thread_t;
typedef struct mutex_t mutex_t;
typedef struct cond_t cond_t;

thread_t* thread_create(PFNTHREADENTRY entry, void* user_data);
void thread_detach(thread_t* thread);

mutex_t* mutex_create();
void mutex_delete(mutex_t* mutex);
bool mutex_trylock(mutex_t* mutex);
void mutex_unlock(mutex_t* mutex);

cond_t* cond_create();
void cond_delete(cond_t* cond);
void cond_wait(cond_t* cond, mutex_t *mutex);
void cond_signal(cond_t* cond);
void cond_broadcast(cond_t* cond);

#endif//THREADS_H
