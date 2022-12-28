#ifndef MEMORY_H
#define MEMORY_H

#define malloc malloc
#define realloc realloc
#define free free

#define new(type) (type*)malloc(sizeof(type))
#define new_(type, mallocfn) (type*)mallocfn(sizeof(type))

#define MemZero(dst, size) memset(dst, 0, size)
#define MemZeroStruct(data) memset(&data, 0, sizeof(data))

#endif//MEMORY_H
