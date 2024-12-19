#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    FILE *file;
    pid_t pid;

    file = fopen("test4.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        fprintf(file, "Child PID: %d\n", getpid());
        fclose(file);
        return 0;
    } else {

        wait(NULL);

        fprintf(file, "Parent PID: %d\n", getpid());
        fclose(file);

        printf("Both PIDs have been written to test4.txt\n");
    }

    return 0;
}
