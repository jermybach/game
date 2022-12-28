#ifndef BASETYPES_H
#define BASETYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;

#define U8_MAX ((u8)0xFF)
#define U16_MAX ((u16)0xFFFF)
#define U32_MAX ((u32)0xFFFFFFFF)
#define U64_MAX ((u64)0xFFFFFFFFFFFFFFFF)

#define S8_MAX ((s8)0x7F)
#define S16_MAX ((s16)0x7FFF)
#define S32_MAX ((s32)0x7FFFFFFF)
#define S64_MAX ((s64)0x7FFFFFFFFFFFFFFF)

#endif//BASETYPES_H
