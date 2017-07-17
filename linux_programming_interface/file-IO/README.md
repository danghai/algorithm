# I/O interface UNIX


### 1. Copy.c

This program is a simple version of the cp(1) command.
It copies the contents of the existing file named in its
first command-line argument to the new file named in its second
command-line argument

Example run:

```sh
danghai@ubuntu:~$ make
gcc -o copy copy.c
danghai@ubuntu:~$ ./copy test.txt test1.txt
danghai@ubuntu:~$ cat test1.txt
Name: Hai Dang Hoang
Email: goldsea5191@gmail.com
This file is created for testing copy the file.
```

### 2. Seek_io.c

This program demonstrates the use of lseek() in conjunction with read() and write()
THe first command-line argument to this program is the name of a file to be opened.
The remaining arguments specify I/O operations to be performed on the file.
Each of these operations consists of a letter followed by an associated value

* soffset: Seek to byte `offset` from the start of the file
* rlength: Read `length` bytes from the file, starting at the current file offset, and
display them in text form
* Rlength: Read `length` bytes from the file, starting at the current file offset, and
display them in hexadecimal form
* wstr : Write the string of characters specified in str at the current file offset.

Example run:

```sh
danghai@ubuntu:~$ touch tFile				==> Create new empty file
danghai@ubuntu:~$ ./seek_io tFile s100 wdanghai		==> Seek to offset 100, write "danghai"
s100: seek succeeded
wdanghai: wrote 7 bytes
danghai@ubuntu:~$ ./seek_io tFile s150 wEmail:danghai@pdx.edu ==> Seek to offset 15, write "Email:danghai@pdx.edu
s150: seek succeeded
wEmail:danghai@pdx.edu: wrote 21 bytes
danghai@ubuntu:~$ ls -l tFile
-rw-rw-r-- 1 danghai danghai 171 Jul 16 15:41 tFile	==> Check size of file
danghai@ubuntu:~$ ./seek_io tFile s100 R20		==> Seek to offset 100, read 20 bytes under hexa format
s100: seek succeeded
R20: 64 61 6e 67 68 61 69 00 00 00 00 00 00 00 00 00 00 00 00 00
danghai@ubuntu:~$ ./seek_io tFile s100 r20		==>  Seek to offset 100, read 20 bytesunder text format
s100: seek succeeded
r20: d a n g h a i ? ? ? ? ? ? ? ? ? ? ? ? ? 
danghai@ubuntu:~$ ./seek_io tFile s150 r30		==> Seek to offset 100, read 30 bytes under text format
s150: seek succeeded
r30: E m a i l : d a n g h a i @ p d x . e d u 		
danghai@ubuntu:~/C-projects-and-Data-Structure/linux_programming_interface/file-IO$
```
