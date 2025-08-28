#ifndef _KUI_LOGGER_H_
#define _KUI_LOGGER_H_

#include <kui_types.h>
#include "kmemory.h"

#define KUI_LOG_INDENT "            "

//  format:
//  [KUI:FATAL] gooning failed successfully

typedef enum kui_log_lvl_e {
    KUI_LOG_LVL_FATAL,
    KUI_LOG_LVL_ERROR,
    KUI_LOG_LVL_WARN,
    KUI_LOG_LVL_INFO,
    KUI_LOG_LVL_DEBUG,
    
    kui_log_lvl_count
} kui_log_lvl_e;

bool kui_log(kui_log_lvl_e lvl, const char *fmt, ...);

#define kui_log_fatal(fmt, ...) kui_log(KUI_LOG_LVL_FATAL, fmt, ##__VA_ARGS__)
#define kui_log_error(fmt, ...) kui_log(KUI_LOG_LVL_ERROR, fmt, ##__VA_ARGS__)
#define kui_log_debug(fmt, ...) kui_log(KUI_LOG_LVL_DEBUG, fmt, ##__VA_ARGS__)
#define kui_log_warn(fmt, ...)  kui_log(KUI_LOG_LVL_WARN,  fmt, ##__VA_ARGS__)
#define kui_log_info(fmt, ...)  kui_log(KUI_LOG_LVL_INFO,  fmt, ##__VA_ARGS__)

#endif // _KUI_LOGGER_H_