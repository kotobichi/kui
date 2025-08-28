#ifndef _KUI_PLATFORM_H_
#define _KUI_PLATFORM_H_

#include <kui_types.h>


// STATE

typedef struct kui_plat_state kui_plat_state_t;

kui_plat_state_t *kui_plat_init(void);
void kui_plat_term(kui_plat_state_t *state);


// MEMORY

void *kui_plat_mem_alloc(uint32_t size);
bool kui_plat_mem_free(void *block);


// WINDOW

typedef struct kui_plat_window kui_plat_window_t;

typedef struct kui_plat_window_config {
    uint16_t width, height;
    const char *title;
    kui_plat_window_t *parent;
} kui_plat_window_config_t;

kui_plat_window_t *kui_plat_window_create(kui_plat_window_config_t *config);
bool kui_plat_window_delete(kui_plat_window_t *window);

#endif // _KUI_PLATFORM_H_