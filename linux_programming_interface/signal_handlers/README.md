# Signal Handlers

### 1. [Ouch.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/signal_handlers/ouch.c)

ouch.c: it is a simple example of a signal handler function and a main
program that establishes it as the handler for the SIGINT signal. (The terminal
driver generates this signal when we type the terminal interrupt character, usually
Control-C). The handler simply prints a message Ouch and returns

```
danghai@ubuntu:~$ ./ouch
0
1
2
^C    Ouch!
3
4
^C    Ouch!
5
```
