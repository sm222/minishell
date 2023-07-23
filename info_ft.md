# Functions Documentation

| Function             | Description                                                                                                                          |
|----------------------|--------------------------------------------------------------------------------------------------------------------------------------|
| [`readline`](https://linux.die.net/man/3/readline)           | Reads a line from standard input and returns it as a dynamically allocated string. It provides line editing and command history.      |
| [`rl_clear_history`](https://linux.die.net/man/3/readline)   | Clears the command history maintained by `readline`.                                                                                 |
| [`rl_on_new_line`](https://linux.die.net/man/3/readline)     | Informs `readline` that the cursor has moved to a new line.                                                                          |
| [`rl_replace_line`](https://linux.die.net/man/3/readline)    | Replaces the current line displayed by `readline` with a new line.                                                                  |
| [`rl_redisplay`](https://linux.die.net/man/3/readline)       | Updates the display after changes made by `rl_replace_line`.                                                                         |
| [`add_history`](https://linux.die.net/man/3/readline)        | Adds a line to the command history maintained by `readline`.                                                                         |
| [`printf`](https://linux.die.net/man/3/printf)             | Prints formatted output to the standard output stream.                                                                               |
| [`malloc`](https://linux.die.net/man/3/malloc)             | Allocates a block of memory on the heap.                                                                                             |
| [`free`](https://linux.die.net/man/3/free)               | Releases previously allocated memory back to the heap.                                                                               |
| [`write`](https://linux.die.net/man/3/write)              | Writes data to a file descriptor.                                                                                                    |
| [`access`](https://linux.die.net/man/2/access)             | Checks if a file can be accessed with specified permissions.                                                                         |
| [`open`](https://linux.die.net/man/3/open)               | Opens a file and returns a file descriptor.                                                                                          |
| [`read`](https://linux.die.net/man/3/read)               | Reads data from a file descriptor into a buffer.                                                                                     |
| [`close`](https://linux.die.net/man/2/close)              | Closes a file descriptor.                                                                                                            |
| [`fork`](https://linux.die.net/man/2/fork)               | Creates a new process by duplicating the existing process.                                                                           |
| [`wait`](https://linux.die.net/man/2/wait)               | Suspends execution of the calling process until a child process terminates.                                                          |
| [`waitpid`](https://linux.die.net/man/2/wait)            | Suspends execution of the calling process until a specific child process terminates.                                                 |
| [`wait3`](https://linux.die.net/man/2/wait3)              | Suspends execution of the calling process until a child process terminates and provides process resource usage information.           |
| [`wait4`](https://linux.die.net/man/2/wait3)              | Suspends execution of the calling process until a specific child process terminates and provides process resource usage information.  |
| [`signal`](https://linux.die.net/man/2/signal)             | Sets a signal handler for a specific signal.                                                                                         |
| [`sigaction`](https://linux.die.net/man/2/sigaction)          | Examines and modifies the action associated with a specific signal.                                                                  |
| [`sigemptyset`](https://linux.die.net/man/3/sigemptyset)        | Initializes an empty signal set.                                                                                                    |
| [`sigaddset`](https://linux.die.net/man/3/sigaddset)          | Adds a signal to a signal set.                                                                                                       |
| [`kill`](https://linux.die.net/man/1/kill)               | Sends a signal to a process or a group of processes.                                                                                  |
| [`exit`](https://linux.die.net/man/3/exit)               | Terminates the calling process and returns an exit status to the parent process.                                                    |
| [`getcwd`](https://linux.die.net/man/3/getcwd)             | Retrieves the current working directory.                                                                                             |
| [`chdir`](https://linux.die.net/man/3/chdir)              | Changes the current working directory.                                                                                               |
| [`stat`](https://linux.die.net/man/2/stat)               | Retrieves information about a file.                                                                                                 |
| [`lstat`](https://linux.die.net/man/2/lstat)              | Retrieves information about a file (does not follow symbolic links).                                                                 |
| [`fstat`](https://linux.die.net/man/2/fstat)              | Retrieves information about a file from a file descriptor.                                                                           |
| [`unlink`](https://linux.die.net/man/2/unlink)             | Removes a specified file from the file system.                                                                                       |
| [`execve`](https://linux.die.net/man/2/execve)             | Replaces the current process image with a new process image.                                                                         |
| [`dup`](https://linux.die.net/man/3/dup)                | Duplicates a file descriptor.                                                                                                        |
| [`dup2`](https://linux.die.net/man/2/dup2)               | Duplicates a file descriptor and replaces an existing file descriptor with it.                                                      |
| [`pipe`](https://linux.die.net/man/2/pipe)               | Creates a pipe, a unidirectional data channel, between two file descriptors.                                                        |
| [`opendir`](https://linux.die.net/man/3/opendir)            | Opens a directory stream.                                                                                                            |
| [`readdir`](https://linux.die.net/man/3/readdir)            | Reads a directory entry from a directory stream.                                                                                     |
| [`closedir`](https://linux.die.net/man/3/closedir)           | Closes a directory stream.                                                                                                           |
| [`strerror`](https://linux.die.net/man/3/strerror)           | Returns a string describing the given error code.                                                                                    |
| [`perror`](https://linux.die.net/man/3/perror)             | Prints an error message to the standard error stream.                                                                                |
| [`isatty`](https://linux.die.net/man/3/isattyn)             | Tests whether a file descriptor refers to a terminal.                                                                                |
| [`ttyname`](https://linux.die.net/man/3/ttyname)            | Returns the name of the terminal associated with a file descriptor.                                                                  |
| [`ttyslot`](https://linux.die.net/man/3/ttyslot)            | Returns the number of the slot in the terminal table associated with a file descriptor.                                              |
| [`ioctl`](https://linux.die.net/man/2/ioctl)              | Performs device-specific operations on file descriptors.                                                                             |
| [`getenv`](https://linux.die.net/man/3/getenv)             | Retrieves the value of an environment variable.                                                                                      |
| [`tcsetattr`](https://linux.die.net/man/3/tcsetattr)          | Sets the attributes of a terminal device.                                                                                            |
| [`tcgetattr`](https://linux.die.net/man/3/tcgetattr)          | Retrieves the attributes of a terminal device.                                                                                       |
| [`tgetent`](https://linux.die.net/man/3/tgetent)            | Initializes the terminfo database.                                                                                                   |
| [`tgetflag`](https://linux.die.net/man/3/tgetflag)           | Retrieves the value of a Boolean capability from the terminfo database.                                                              |
| [`tgetnum`](https://linux.die.net/man/3/tgetnum)            | Retrieves the value of a numeric capability from the terminfo database.                                                              |
| [`tgetstr`](https://linux.die.net/man/3/tgetstr)            | Retrieves the value of a string capability from the terminfo database.                                                               |
| [`tgoto`](https://linux.die.net/man/3/tgoto)              | Translates the given parameters to cursor motion string using the capabilities from the terminfo database.                          |
| [`tputs`](https://linux.die.net/man/3/tputs)              | Outputs the given string to the terminal using the capabilities from the terminfo database.                                          |