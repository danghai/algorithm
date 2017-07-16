# I/O interface UNIX 


### 1. Copy.c

This program is a simple version of the cp(1) command.
It copies the contents of the existing file named in its
first command-line argument to the new file named in its second
command-line argument

```
danghai@ubuntu:~$ make
gcc -o copy copy.c
danghai@ubuntu:~$ ./copy test.txt test1.txt
danghai@ubuntu:~$ cat test1.txt
Name: Hai Dang Hoang
Email: goldsea5191@gmail.com
This file is created for testing copy the file. 
```



