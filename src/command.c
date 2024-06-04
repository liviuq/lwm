#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <X11/Xlib.h>

#include "command.h"

uint32_t handle_command(Display *display, XEvent *ev, size_t keys)
{
    // 1 key commands
    switch (keys) {
        case 1:
            //handle_single_key(&ev[0]);
            break;
        case 2:
            handle_double_key(display, ev);
            break;
        case 3:
            break;
        default:
            return 0;
    }

    return 0;
}

uint32_t handle_double_key(Display *display, XEvent *ev)
{

}