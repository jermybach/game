#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "macros.h"

#define DIRECTORY_ENTRY_PATHNAME_MAX 260

typedef struct directory_iterator_t directory_iterator_t;

typedef enum {
    DIRECTORY_ENTRY_NORMAL = BIT(1),
    DIRECTORY_ENTRY_DIRECTORY = BIT(2),
} directory_entry_flags_t;

typedef struct {
    char path[DIRECTORY_ENTRY_PATHNAME_MAX];
    size_t size;
    directory_entry_flags_t flags;
} directory_entry_t;

/**
 * @brief Function to begin iterating through files in a directory
 * @param path Path to the folder
 * @param entry pointer to a struct to hold file details
*/
directory_iterator_t* dir_open(const char* path, directory_entry_t* entry);
bool dir_next(directory_iterator_t* iter, directory_entry_t* entry);

#endif//FILESYSTEM_H
