#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "window.h"
#include "logger.h"

void print_window_attributes(Display *display, Window *window)
{
    XWindowAttributes attributes;
    char *name;
    if (XGetWindowAttributes(display, *window, &attributes) == 0)
    {
        log_error("XGetWindowAttributes failed.");
        exit(EXIT_FAILURE);
    }
    XFetchName(display, *window, &name);

    printf("%s | (%d, %d) | %dx%d\n", name, attributes.x, attributes.y, attributes.width, attributes.height);
    if (name)
    {
        XFree(name);
    }
}