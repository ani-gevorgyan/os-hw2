#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t ret = fork();

    if (ret == -1) {
        perror("ERROR: fork");
        return 1;
    }

    if (ret == 0) {
        // Child: replace its program with ls.
        execl("/bin/ls", "ls", (char *)NULL);

        // Reached only if execl fails.
        perror("ERROR: execl");
        return 1;
    } else {
        // Parent: wait for this child to finish.

        ret = waitpid(ret, NULL, 0);  // Parent waits here.
        
        if (ret == -1) {
            perror("ERROR: waitpid");
            return 1;
        }

        printf("Parent process done\n");
    }

    return 0;
}
