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
        // Child: replace its program with ls.
        execl("/bin/ls", "ls", NULL);

        // Reached only if execl fails.
        perror("ERROR: execl 1");
        return 1;
    } else {
        // Parent: wait for this child to finish.
        pid_t ret = waitpid(ret_1, NULL, 0);
        if (ret == -1) {
            perror("ERROR: waitpid 1");
            return 1;
        }
      
        pid_t ret_2 = fork();
        
        if(ret_2 == -1) {
            perror("ERROR: fork 2");
            return 1;
        }
        
        if(ret_2 == 0) {  
            execl("/bin/date", "date", NULL);

            // Reached only if execl fails.
            perror("ERROR: execl 2");
            return 1;
        }

        ret = waitpid(ret_2, NULL, 0);  // Parent waits here.
        if (ret == -1) {
            perror("ERROR: waitpid 2");
            return 1;
        }

        printf("Parent process done\n");
    }

    return 0;
}
