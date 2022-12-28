/**
 * @file common/extension.h
 * The extension api provides an interface to interact with engine code/functions from shared libraries.
*/
#ifndef EXTENSION_H
#define EXTENSION_H
typedef struct {
    int version;
    
} extension_imports_t;

extern extension_imports_t extension_imports;

#endif//EXTENSION_H
