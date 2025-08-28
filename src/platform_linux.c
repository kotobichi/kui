#include "platform.h"

#include "array.h"

#include <stdlib.h>
#include <xcb/xcb.h>

struct kui_plat_window_t {
    uint16_t width, height;
};

struct kui_plat_state_t {
    kui_array8_t windows;
    
    xcb_connection_t *connection;
    xcb_window_t window;
    xcb_screen_t *screen;
    xcb_atom_t wm_protocols;
    xcb_atom_t wm_delete_win;
};

void *kui_plat_mem_alloc(uint32_t size) {
    return malloc(size);
}
void kui_plat_mem_free(void *block) {
    free(block);
}