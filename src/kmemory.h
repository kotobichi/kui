#ifndef _KUI_MEMORY_H_
#define _KUI_MEMORY_H_

#include <kui_types.h>

typedef enum kui_mem_tag {
    KUI_MEM_TAG_UNKNOWN,
    KUI_MEM_TAG_ARRAY,
    KUI_MEM_TAG_DYNARRAY,
    KUI_MEM_TAG_HASHMAP,
    KUI_MEM_TAG_STRING,
    
    kui_mem_tag_count
} kui_mem_tag_t;

bool kui_mem_init(void);
bool kui_mem_term(void);

void *kui_mem_alloc(uint32_t size, kui_mem_tag_t tag);
bool kui_mem_free(void *ptr, uint32_t size, kui_mem_tag_t tag);

void *kui_mem_zero(void *block, uint32_t size);
void *kui_mem_copy(void *dest, const void *src, uint32_t size);
void *kui_mem_set(void *dest, int8_t value, uint32_t size);

// #define kui_mem_set(dest, value, size)      \ 
// for (uint32_t i = 0; i < size; i++) dest[i] = value;

uint32_t kui_mem_usage(kui_mem_tag_t tag);

#endif // _KUI_MEMORY_H_