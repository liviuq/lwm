#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "logger.h"
#include "window.h"

int main(int argc, char **argv)
{
    logger("INFO", "Welcome to lwm");
    Display *display = XOpenDisplay(NULL);
    Window rootw = DefaultRootWindow(display);

    Window root_return, parent_return, *children_return;
    uint32_t nchildren_return;

    Status status = XQueryTree(display, rootw, &root_return, &parent_return, &children_return, &nchildren_return);
    if (status == 0)
    {
        logger(LOG_ERROR, "XQueryTree failed.");
        exit(EXIT_FAILURE);
    }

    for (uint32_t i = 0; i < nchildren_return; i++)
    {
        print_window_attributes(display, &children_return[i]);
    }

    XCloseDisplay(display);
}