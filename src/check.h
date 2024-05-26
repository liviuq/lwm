#ifndef CHECK_H_
#define CHECK_H

#include <X11/Xlib.h>

void checkwm(Display *display);
static int xerrorstart(Display *display, XErrorEvent *ee);
static int xerror(Display *display, XErrorEvent *ee);

#endif