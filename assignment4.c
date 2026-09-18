#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    if(argc < 2) {
        printf("No arguments provided (Program name: %s)\n", argv[0]);
        return 1;
    }
    
    pid_t ret_1 = fork();

    if (ret_1 == -1) {
        perror("ERROR: fork");
        return 1;
    }

    if (ret_1 == 0) {
        // Child: replace its program with grep with arguments.
        execl("/bin/grep", "grep", "--color=auto", "main", argv[1], NULL);

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
      
        printf("Parent process completed\n");
    }

    return 0;
}
