#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "loop.h"

void run(Display *display)
{
    XEvent ev;

    // set root window to listen to KeyPressMask
    XSelectInput(display, DefaultRootWindow(display), KeyPressMask | KeyReleaseMask);

    bool running = true;

    while(running)
    {
        while (XPending(display)) {
            XNextEvent(display, &ev);

            switch (ev.type) {
                case KeyPress:
                    printf("KeyPress!: %d\n", ev.xkey.keycode);
                    break;
                case KeyRelease:
                    printf("KeyRelease!: %d\n", ev.xkey.keycode);
                    break;
            }
        }
    }
}