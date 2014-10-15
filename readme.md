IOCCC submission
================

How to build
------------

Use the make file. When trying to do it manually: cc prog.c -o prog -Wall -pedantic -std=c99  -O2 -lncurses

This entry depends on ncurses

How to use
----------

When running ./prog.c it looks for its demo file called: "<file name>.life" so "prog.life" in this case.

But the real fun starts when user input is used. A good example is to run "./prog prog.c". In this case it will use its source file as input file. 
To be able to run this a reasonable sized screen is required (Tested with 179 colomns & 52 rows). When a sufficiently large screen resolution is used the source file will result in a stabile demo.
Smaller screens will result in cropping of the input file.

Online a lot of demo's can be found. Small conversion with a text editor might be required.
