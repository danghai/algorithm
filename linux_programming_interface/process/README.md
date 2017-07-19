# Process 

### 1. [Folk_file_sharing.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/process/fork_file_sharing.c)

When a `fork()` is performed, the child receives duplicates of all the parent's file
descriptos. These duplicates are made in the manner of `dup()`, which means that 
corresponding descriptors in the parent and the child refer to the same open file description
Consequently, these attributes of an open file are shared between the parent and child. 

fork_file_sharing.c: Program illustrate sharing file between parent and child. Program  
opens a file, and then call fork() to create a child process. The child changes 
the file offset and status flags of the file, and exits. The parent then retrieves 
the file offset and flags to verify that it can see the changes made by the child.

Example run:

```
danghai@ubuntu:~$ ./fork_file_sharing example
File offset before fork(): 0
O_APPEND flag before fork() is: OFF
---------------------------------------- Child is exited 
File offset after fork(): 100
O_APPEND flag after fork() is: ON
```
