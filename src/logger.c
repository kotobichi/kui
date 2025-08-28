#include "logger.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "kmemory.h"

#define KUI_LOG_C_RESET     0
#define KUI_LOG_C_BOLD      1
#define KUI_LOG_C_ITALIC    3
#define KUI_LOG_C_UNDERLINE 4

#define KUI_LOG_C_BLACK   30
#define KUI_LOG_C_RED     31
#define KUI_LOG_C_GREEN   32
#define KUI_LOG_C_YELLOW  33
#define KUI_LOG_C_BLUE    34
#define KUI_LOG_C_MAGENTA 35
#define KUI_LOG_C_CYAN    36
#define KUI_LOG_C_WHITE   37

#define KUI_LOG_C_BRIGHT 60
#define KUI_LOG_C_GRAY KUI_LOG_C_BLACK + KUI_LOG_C_BRIGHT

static void print_c(const uint8_t c) { printf("\033[%im", c); }

bool kui_log(kui_log_lvl_e lvl, const char *fmt, ...) {
    assert(lvl < kui_log_lvl_count);
    assert(fmt);

    const uint16_t log_len = 2048;
    char log[log_len];
    kui_mem_zero(&log, log_len);

    va_list args;
    va_start(args, fmt);
    vsnprintf(log, log_len, fmt, args);
    va_end(args);

    struct level { const uint8_t color; const char *str; };
    const struct level levels[kui_log_lvl_count] = {
        { .color = KUI_LOG_C_MAGENTA,       .str = "FATAL" },
        { .color = KUI_LOG_C_RED,           .str = "ERROR" },
        { .color = KUI_LOG_C_YELLOW,        .str = "WARN " },
        { .color = KUI_LOG_C_WHITE,         .str = "INFO " },
        { .color = KUI_LOG_C_CYAN,          .str = "DEBUG" },
    };

    print_c(KUI_LOG_C_RESET);
    print_c(KUI_LOG_C_BOLD);
    printf("[");
    print_c(KUI_LOG_C_GREEN);
    printf("KUI");
    print_c(KUI_LOG_C_GRAY);
    printf(":");
    print_c(levels[lvl].color);
    printf(levels[lvl].str);
    print_c(KUI_LOG_C_WHITE);
    printf("] ");
    print_c(KUI_LOG_C_RESET);
    print_c(levels[lvl].color);
    printf("%s\n", log);
    print_c(KUI_LOG_C_RESET);
}