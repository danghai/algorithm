# I/O interface UNIX


### 1. [Copy.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/file-IO/copy.c)

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

### 2. [Seek_io.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/file-IO/seek_io.c)

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
danghai@ubuntu:~$ ./seek_io tFile s100 r20		==>  Seek to offset 100, read 20 bytes sunder text format
s100: seek succeeded
r20: d a n g h a i ? ? ? ? ? ? ? ? ? ? ? ? ? 
danghai@ubuntu:~$ ./seek_io tFile s150 r30		==> Seek to offset 100, read 30 bytes under text format
s150: seek succeeded
r30: E m a i l : d a n g h a i @ p d x . e d u 		

```

### 3. [Tee.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/file-IO/tee.c)

The tee command reads its standard input until end-of-file, writing a copy
of the input to standard output and to the file named in its command-line
argument. By default, tee overwrites any existing file with the given name.
Implement the -a command-line option (tee -a file),  which causes
tee to append text to the end of a file if it already exists.

### 4. [Atomic_append](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/file-IO/atomic_append.c)

This program is designed to demonstrate why the atomicity guaranteed
by opening a file with the O_APPEND flag is necessary. Write a program
that takes up to three command-line arguments:

```
	$ ./atomic_append <filename> <num-bytes> [x]
```

This program should open the specified filename (creating it if necessary)
and append num-bytes to the file by using write() to write a byte at a time.
By default, the program should open the file with the O_APPEND flag, but if a
third command-line argument (x) is supplied, O_APPEND flag should be omitted,
and instead, the program should perform and lseek(fd, 0, SEEK_END) call before
each write(). Run two instances of this program at the same time without the x
argument to write 1 million bytes to the same file:

```
	$ ./atomic_append f1 10000000 & ./atomic_append f1 10000000
```
Repeat the same steps, writing to a different file, but this time specifying the x argument:

```
	$ atomic_append f2 10000000 x & ./atomic_append f2 10000000 x
```

Result: f2 was run without O_APPEND. f2 has less number of bytes, as well as number of
time than f1. Because its seeking to the end of the file do not take place at the same time as the write


