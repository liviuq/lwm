#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#include "logger.h"
#include "loop.h"
#include "command.h"

void run(Display *display)
{
    // set root window to listen to KeyPressMask
    XSelectInput(display, DefaultRootWindow(display), KeyPressMask);

    XWindowAttributes attrib;
    if(XGetWindowAttributes(display, DefaultRootWindow(display), &attrib) == 0)
    {
        log_error("error getting window attributes");
        exit(EXIT_FAILURE);
    }

    int width = attrib.width, height = attrib.height;
    uint32_t count = 0;
    XEvent ev[2];

    bool running = true;
    while(running)
    {      
        while (XPending(display))
        {
            if(count < 1)
            {
                XNextEvent(display, &ev[count++]);
            }
            else if(count == 1)
            {
                XNextEvent(display, &ev[count]);

                // TODO: fork this to handle in a new thread
                if(handle_command(display, ev, sizeof ev) != 0)
                {
                    running = false;
                    break;
                }

                count = 0;
                break;
            }
        }
    }

    logger("INFO", "exiting event loop");
}