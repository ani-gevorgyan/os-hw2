#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t ret_1 = fork();

    if (ret_1 == -1) {
        perror("ERROR: fork 1");
        return 1;
    }

    if (ret_1 == 0) {
        // Child: replace its program with echo.
        execl("/bin/echo", "echo", "Hello from the child process", NULL);

        // Reached only if execl fails.
        perror("ERROR: execl 1");
        return 1;
    } else {
        // Parent: wait for this child to finish.
        pid_t ret = waitpid(ret_1, NULL, 0);
        if (ret == -1) {
            perror("ERROR: waitpid");
            return 1;
        }
      
        printf("Parent process done.\n");
    }

    return 0;
}
