#include "logger.h"
int DEBUG = 0;

static const char LOG_LEVEL_INFO[] = "\033[0m";
static const char LOG_LEVEL_DEBUG[] = "\033[1;33m";
static const char LOG_LEVEL_ERROR[] = "\033[1;31m";


static void reiniciar();
static void print(const char *level, const char *formato, va_list args);


void log_info(const char *formato, ...){
    va_list arg;
    va_start(arg, formato);
    print(LOG_LEVEL_INFO, formato, arg);
    va_end(arg);
}

void log_error(const char *formato, ...){
    va_list arg;
    va_start(arg, formato);
    print(LOG_LEVEL_ERROR, formato, arg);
    va_end(arg);
}

void log_debug(const char *formato, ...){
    if (DEBUG){
        va_list arg;
        va_start(arg, formato);
        print(LOG_LEVEL_DEBUG, formato, arg);
        va_end(arg);
    }
}


static void print(const char level[], const char *formato, va_list args){
    printf("%s", level);
    vfprintf(stdout, formato, args);
    reiniciar();
}

static void reiniciar(void){
    printf("%s", LOG_LEVEL_INFO);
}

