#ifndef CHECK_H
#define CHECK_H

#include <X11/Xlib.h>

void checkwm(Display *display);
int xerrorstart(Display *display, XErrorEvent *ee);
int xerror(Display *display, XErrorEvent *ee);

#endif