# dprintf_lib
A small library of functions coded from libc functions coded from scratch along with a mini version of dprintf.

The dprintf supports %d, %i, %u, %s, %c, %p, %x, %X conversions along with the  ( .   , 0  ,  -   ,  * ) flags. (dot, zero, minus, wildcard).

## Man dprintf

The functions dprintf() and vdprintf() (as found in the glibc2 library) are exact analogs of fprintf(3) and vfprintf(3), except that they output to a file descriptor fd instead of to a stdio stream.
