#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "logger.h"
#include "check.h"
#include "loop.h"

int
main(int argc, char **argv)
{
    Display *display = NULL;
    if (argc > 1)
    {
        logger("ERROR", "too many arguments");
        exit(EXIT_FAILURE);
    }
    
    if(!(display = XOpenDisplay(NULL)))
    {
        log_error("cannot open display");
        exit(EXIT_FAILURE);
    }

    checkwm(display);
    run(display);
    return 0;
}