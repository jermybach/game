#pragma once

#define list_t(type)                                                           \
        struct                                                                 \
        {                                                                      \
                type *data;                                                    \
                uint32_t size;                                                 \
                uint32_t capacity;                                             \
        }

#define list_type_size(list) (sizeof(*(list.data)))

#define list_resize(list, new_size)                                            \
        do                                                                     \
        {                                                                      \
                if (list.capacity < new_size)                                  \
                {                                                              \
                        list.data = realloc(list.data,                         \
                                            list_type_size(list) * new_size);  \
                }                                                              \
                list.size = new_size;                                          \
        } while (0)

#define list_push(list, value)                                                 \
        do                                                                     \
        {                                                                      \
                list_resize(list, list.size + 1);                              \
                list.data[list.size - 1] = value;                              \
        } while (0)

#define list_free(list)                                                        \
        do                                                                     \
        {                                                                      \
                free(list.data);                                               \
        } while (0)

