#include "../core.h"
#include "../filesystem.h"
#include "win32_private.h"
#if OS_WINDOWS

struct directory_iterator_t {
    HANDLE hFind;
    directory_entry_flags_t mask;
};

inline 
void fill_entry(WIN32_FIND_DATA* ffd, directory_entry_t* entry)
{
    memcpy(entry->path, ffd->cFileName, 260-1);
    entry->path[259] = '\0';
    entry->size = ffd->nFileSizeLow | (ffd->nFileSizeHigh << 32);
}

directory_iterator_t* dir_open(const char* path, directory_entry_t* entry)
{
    directory_iterator_t* iter = new(directory_entry_t);
    WIN32_FIND_DATA ffd;
    iter->hFind = FindFirstFileA(path, &ffd);
    if (!iter->hFind) {
        return NULL;
    }
    fill_entry(&ffd, entry);
    return iter;
}

bool dir_next(directory_iterator_t* iter, directory_entry_t* entry)
{
    bool result;
    WIN32_FIND_DATA ffd;
    result = (bool)FindNextFileA(iter->hFind, &ffd);
    fill_entry(&ffd, entry);
    return result;
}

#endif
