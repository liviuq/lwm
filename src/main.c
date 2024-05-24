#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char **argv)
{
    Display *display = XOpenDisplay(NULL);
    Window rootw = DefaultRootWindow(display);
    Window root_return, parent_return, *children_return;
    uint32_t nchildren_return;

    Status status = XQueryTree(display, rootw, &root_return, &parent_return, &children_return, &nchildren_return);
    if (status == 0)
    {
        perror("XQuery tree failed\n");
        exit(EXIT_FAILURE);
    }

    for (uint32_t i = 0; i < nchildren_return; i++)
    {
        XWindowAttributes attrib;
        char *name;
        (void)XGetWindowAttributes(display, children_return[i], &attrib);
        (void)XFetchName(display, children_return[i], &name);
        if (name != NULL && strcmp("Discord", name) == 0)
        {
            XMoveWindow(display, children_return[i], 1000, 1000);
            XResizeWindow(display, children_return[i], 500, 500);
            XMapWindow(display, children_return[i]);
            XFlush(display);
        }
        printf("%s -> (%d,%d), %d x %d\n", name, attrib.x, attrib.y, attrib.width, attrib.height);
    }

    XCloseDisplay(display);
}