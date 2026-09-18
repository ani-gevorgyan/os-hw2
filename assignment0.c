#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t ret1 = fork();                 // First fork

    if (ret1 == -1) {
        perror("First fork failed");
        return 1;
    }

    if (ret1 == 0) {
        // Child of the first fork
        pid_t ret2 = fork();             // Second fork

        if (ret2 == -1) {
            perror("Second fork failed");
            return 1;
        }

        if (ret2 == 0) {
            // Child of the second fork
            pid_t ret3 = fork();         // Third fork

            if (ret3 == -1) {
                perror("Third fork failed");
                return 1;
            }
        } else {
            // Parent of the second fork
            pid_t ret3 = fork();         // Third fork

            if (ret3 == -1) {
                perror("Third fork failed");
                return 1;
            }
        }
    } else {
        // Original parent
        pid_t ret2 = fork();             // Second fork

        if (ret2 == -1) {
            perror("Second fork failed");
            return 1;
        }

        if (ret2 == 0) {
            // Child of the second fork
            pid_t ret3 = fork();         // Third fork

            if (ret3 == -1) {
                perror("Third fork failed");
                return 1;
            }
        } else {
            // Original parent
            pid_t ret3 = fork();         // Third fork

            if (ret3 == -1) {
                perror("Third fork failed");
                return 1;
            }
        }
    }

    // All eight processes reach this line if all forks succeed.
    printf("Process PID: %ld\n", (long)getpid());

    return 0;
}
