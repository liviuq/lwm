#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include "logger.h"

const char *get_current_time_no_endl();

void logger(const char *tag, const char *message)
{
    printf("%s [%s]: %s\n", get_current_time_no_endl(), tag, message);
}

void log_error(const char *message)
{
    printf("%s [" KRED "%s" KNRM "]: %s. %sd\n", get_current_time_no_endl(), LOG_ERROR, message, strerror(errno));
}

const char *get_current_time_no_endl()
{
    time_t now;
    time(&now);
    char *time_string = ctime(&now);
    time_string[strlen(time_string) - 1] = 0;
    return time_string;
}