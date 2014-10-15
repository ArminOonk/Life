IOCCC submission
================

How to build
------------

Use the make file or when trying to do it manually: cc prog.c -o prog -Wall -pedantic -std=c99  -O2 -lncurses

This entry depends on ncurses.

How to use
----------

The real fun starts when user input is used. The best example is to run "./prog prog.c". In this case it will use its source file as input file. 
To be able to run this a reasonable sized screen is required (Tested with 179 columns & 52 rows). When a sufficiently large screen resolution is used the source file will result in a stable demo.
Smaller screens will result in cropping of the input file.

When running without an argument ./prog.c it looks for its demo file called: "<file name>.life" so "prog.life" in this case.

When /dev/urandom is used the results are not clear.

Online a lot of demo's can be found. (NOTE: Small conversion with a text editor might be required.)

Obfuscation
-----------
* Sorry for the blob on the end
* Short variable/function names
* Put stuff together in one unit which is not related
* Strings are obfuscated
* Not following a coding convention
* Use of function pointer. (Next time I will integrate these on a much lower level)
* a[b] == b[a]
* Ignore my own rules
* goto next_point;
* next_point: Try a different looping strategy in every function
* Very professionally call variables->units