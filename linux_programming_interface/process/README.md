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

### 2. [Multi_wait.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/process/multi_wait.c)

multi_wait.c: program demonstrates the use of wait(). This program
creates multiple child processes, one per command-line argument.
Each child sleeps for the number of second specified in the
corresponding command-line argument and then exits. In the meantime,
after all children have been created, the parent process repeatedly calls
wait() to monitor the termination of its children. This loop continues until
wait() returns -1. The following shell session log shows what happens when
we use the program:

```
danghai@ubuntu:~$ ./multi_wait 4 2 10 8
Child 4 startd with PID 8688, sleeping 8 seconds
Child 3 startd with PID 8687, sleeping 10 seconds
Child 2 startd with PID 8686, sleeping 2 seconds
Child 1 startd with PID 8685, sleeping 4 seconds
wait() return child PID 8686 (numChild = 1)
wait() return child PID 8685 (numChild = 2)
wait() return child PID 8688 (numChild = 3)
wait() return child PID 8687 (numChild = 4)
No more children - bye!
```

### 3. [Make_zombie.c](https://github.com/danghai/C-projects-and-Data-Structure/blob/master/linux_programming_interface/process/make_zombie.c)

The program demonstrates the creation of a zombie
and that a zombie cannot killed by SIGKILL. It should be killed by
kill their parent.

```
danghai@ubuntu:~$ ./make_zombie
Parent PID = 2618
Child (PID = 2619) exiting
  2618 pts/17   00:00:00 make_zombie
  2619 pts/17   00:00:00 make_zombie <defunct>
After sending SIGKILL to zombie (PID = 2619):
  2618 pts/17   00:00:00 make_zombie
  2619 pts/17   00:00:00 make_zombie <defunct>
Killed
```
