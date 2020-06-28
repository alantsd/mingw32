# mingw32
mingw32-make

This is for solving common mingw32-make error without installing MSYS2.
This is actually proxy version that call the actual windows version.

Make show error when using windows version of mkdir:

```javascript
process_begin: CreateProcess(NULL, rm -f -r Debug/, ...) failed.
make (e=2): The system cannot find the file specified.
```

Make show error when rm command is not found:
```javascript
process_begin: CreateProcess(NULL, makedir Debug, ...) failed.
make (e=2): The system cannot find the file specified.
```

Built the main.c to rm.exe and mkdir.exe, then place it to mingw32 /bin installation folder.
e.g. copy rm.exe and mkdir.exe to C:\MinGW\bin



