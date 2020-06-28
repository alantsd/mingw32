# mingw32
mingw32-make

Make show error when using windows version of mkdir:

process_begin: CreateProcess(NULL, rm -f -r Debug/, ...) failed.
make (e=2): The system cannot find the file specified.

Make show error when rm command is not found:
process_begin: CreateProcess(NULL, makedir Debug, ...) failed.
make (e=2): The system cannot find the file specified.





