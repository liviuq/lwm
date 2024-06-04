#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>
#include <stdbool.h>
#include <X11/Xlib.h>

uint32_t handle_command(Display *display, XEvent *ev, size_t keys);
uint32_t handle_double_key(Display *display, XEvent *ev);

#endif