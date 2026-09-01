<div align="center">
    <h1>get_next_line</h1>
</div>

<div align="center">
    <h2>DESCRIPTION :</h2>
</div>

This project is also usefull for most of our next C projects of the common core. On this project, we have created a function called `get_next_line()` who will read a line on file descriptor. The string return by the function is allocated dynamicly using `malloc()`, it should freed using `free()` before the end of the execution.

<div align="center">
    <h2>INSTALLATION : </h2>
</div>

- Compile the library
```sh
make
# OR
make bonus
```
- Remove every object files
```sh
make clean
```
- Remove every object files and the compiled library
```sh
make fclean
```

<div align="center">
    <h2>FUNCTION AVAILABLE :</h2>
</div>
| Function | Purpose |
| --------- | ------- |
| char *get_next_line(int fd)        | Get the next line on the file descriptor (fd) |
