<div align="center">
    <h1>minitalk</h1>
</div>

<div align="center">
    <h2>DESCRIPTION : </h2>
</div>

A client-server communication project that uses only SIGUSR1 and SIGUSR2 UNIX signals to transmit strings. 

<div align="center">
    <h2>INSTALLATION : </h2>
</div>

1. Compile the library
```sh
make
```
- To launch the server
```sh
./server
```
- To send a message using the client
```sh
./client PID_OF_THE_SERVER MESSAGE_TO_SEND
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
    <h2>SKILL LEARNED : </h2>
</div>

- Learned about IPC 
- Learned about bitwise operation