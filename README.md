# lwm (learn window manager)

lwm is a window manager for learning purposes. It shares some functionality wiht suckless's dwm.

# Building

Building lwm requires X11 and make

    $ git clone git@github.com:liviuq/lwm.git
    $ cd lwm
    $ make {debug, release}

# Debugging lwm

To debug, you need Xephyr.

    $ Xephyr -br -ac -noreset -screen 1280x720 :2 &
    $ DISPLAY=:2 gdb lwm
    