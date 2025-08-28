#include "kmemory.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "platform.h"

struct mem_state { 
    uint32_t total; // total amount of memory allocated
    uint32_t tags[kui_mem_tag_count]; // per tag allocation total
};
static struct mem_state state;

void kui_mem_init(void) { kui_mem_zero(&state, sizeof(state)); }

void *kui_mem_alloc(uint32_t size, kui_mem_tag_t tag) {
    assert(size > 0); 
    assert(tag < kui_mem_tag_count);

    if (tag == KUI_MEM_TAG_UNKNOWN) {
        kui_log_warn("memory allocation tagged UNKNOWN");
    }
    void *block = kui_plat_mem_alloc(size);
    if (!block) return NULL;

    // update mem state
    state.total     += size;
    state.tags[tag] += size;
    // zero out mem
    if (!kui_mem_zero(block, size)) {
        kui_log_error("failed to zero out newly allocated memory");
    }
    return block;
}
bool kui_mem_free(void *block, uint32_t size, kui_mem_tag_t tag) {
    assert(size > 0); 
    assert(tag < kui_mem_tag_count);

    if (!block) {
        kui_log_error("attemp to free a null pointer");
        return false;
    } else {
        kui_plat_mem_free(block);   // free mem block
        block = NULL;               // no dangling :3
        // update mem state
        state.total     -= size; 
        state.tags[tag] -= size; 
        return true;
    }
}

void *kui_mem_zero(void *block, uint32_t size) {
    assert(block);
    assert(size > 0);
    return memset(block, 0, size);
}
void *kui_mem_copy(void *dest, const void *src, uint32_t size) {
    assert(dest);
    assert(src);
    assert(size > 0);
    return memcpy(dest, src, size);
}
void *kui_mem_set(void *dest, int8_t value, uint32_t size) {
    assert(dest);
    assert(size > 0);
    return memset(dest, value, size);
}