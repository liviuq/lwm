#ifndef LOGGER_H
#define LOGGER_H

#define LOG_ERROR "ERROR"
#define LOG_WARNING "WARNING"
#define LOG_INFO "INFO"

#include "colors.h"

void logger(const char *tag, const char *message);
void log_error(const char *message);

#endif