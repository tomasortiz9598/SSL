#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void log_info(const char *formato, ...);
void log_error(const char *formato, ...);
void log_debug(const char *formato, ...);
extern int DEBUG;
