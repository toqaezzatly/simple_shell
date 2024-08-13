Here's a well-structured README file for your `simple_shell` project:

### `README.md`

```markdown
# Simple Shell

## Description

The Simple Shell project is a basic UNIX command line interpreter. It is designed to emulate a simple shell environment, allowing users to execute commands and interact with the system. This project is developed as part of the ALX Software Engineering program.

## Features

- Displays a prompt and waits for the user to type a command.
- Executes commands entered by the user.
- Handles errors gracefully.
- Handles the "end of file" condition (Ctrl+D).
- Does not support advanced features like semicolons, pipes, redirections, or special characters.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 20.04 LTS using `gcc`, with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file at the root of the project is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- The shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when necessary

## List of Allowed Functions and System Calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## Compilation

To compile the shell, use the following command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

To start the shell, run the following command:

```sh
./hsh
```

### Interactive Mode

In interactive mode, the shell displays a prompt and waits for the user to type a command. For example:

```sh
$ ./hsh
#cisfun$ /bin/ls
simple_shell main.c shell.c
#cisfun$ exit
$
```

### Non-Interactive Mode

In non-interactive mode, the shell reads commands from a file or pipe and executes them. For example:

```sh
$ echo "/bin/ls" | ./hsh
simple_shell main.c shell.c
$
```

## Example

```sh
$ ./hsh
#cisfun$ /bin/ls
hsh main.c shell.c
#cisfun$ /bin/pwd
/home/user/simple_shell
#cisfun$ /bin/echo "Hello, world!"
Hello, world!
#cisfun$ exit
$
```

## Authors

- Your Name <your.email@example.com>
- Partner's Name <partner.email@example.com>

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

### Explanation

- **Description**: Provides an overview of the project.
- **Features**: Lists the key features and limitations of the shell.
- **Requirements**: Specifies the development environment and coding standards.
- **Allowed Functions and System Calls**: Lists the allowed functions and system calls.
- **Compilation**: Provides the command to compile the shell.
- **Usage**: Explains how to run the shell in interactive and non-interactive modes.
- **Example**: Shows an example interaction with the shell.
- **Authors**: Lists the authors of the project.
- **License**: Specifies the license for the project.

This README should give a clear and comprehensive overview of your project, its requirements, and how to use it.
