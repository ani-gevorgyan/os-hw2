# Operating Systems Homework 2

These C programs demonstrate how to create child processes with `fork()`, run commands with `execl()`, and wait for children to finish with `waitpid()`.

## Assignments

- **assignment0.c:** Uses three stages of forks to create eight processes in total, assuming all calls succeed. Each process prints its PID.
- **assignment1.c:** Creates a child that runs `ls`. The parent waits, then prints its completion message.
- **assignment2.c:** Creates two children to run `ls` and `date`. The parent waits for the first child before creating the second, so the listing appears before the date.
- **assignment3.c:** Creates a child that runs `echo` with the message "Hello from the child process". The parent prints its message afterward.
- **assignment4.c:** Creates a child that runs `grep` to find lines containing `main` in a file supplied as an argument. Matches are highlighted when the output goes to a terminal.

## Compile and run

Use GCC on Linux. For example:

```bash
gcc assignment1.c -o assignment1
./assignment1
```

Use the corresponding filename for the other assignments.

For Assignment 4, create a `test.txt` file with some text, including lines containing `main`, then run:

```bash
gcc assignment4.c -o assignment4
./assignment4 test.txt
```
