#include <stdlib.h>
#include <X11/Xlib.h>

#include "logger.h"
#include "check.h"

void
checkwm(Display *display)
{
    XSetErrorHandler(xerrorstart);
    // this will cause an error if another wm is running
    XSelectInput(display, DefaultRootWindow(display), SubstructureRedirectMask);
    XSync(display, False);
    XSetErrorHandler(xerror);
    XSync(display, False);
}

int
xerrorstart(Display *display, XErrorEvent *ee)
{
    log_error("another wm is already running");
    exit(EXIT_FAILURE);
}

int
xerror(Display *display, XErrorEvent *ee)
{
    logger("INFO", "xerror");
    return ee->error_code;
}