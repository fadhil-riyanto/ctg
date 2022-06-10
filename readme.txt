CTG - C Telegram Bot
-------------------
This is C Telegram Bot basic on telegram api, and accesed with curl.
this bot run with traditional method, not mtproto

setup
------
- install curl (dev)
- install cmake, then cmake
- then. make

optional: use cmake debug mode for debugging with GDB.
follow instruction on the program for token set.

how to build.
- make sure on your computer installed curl dev, and json-c
- after that, make "build" directory.
- change directory to build
- and generate make config file. you can also add parameter -DCMAKE_BUILD_TYPE=debug for include debug on binary
- after that, you will get the binary output.

License
--------
GPL 2.0 