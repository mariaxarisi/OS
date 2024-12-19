#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]);  // Close the write end of the pipe

        // Read messages from the pipe
        while (1) {
            ssize_t bytesRead = read(pipefd[0], buffer, BUFFER_SIZE - 1);

            if (bytesRead == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            } else if (bytesRead == 0) {
                break;
            }

            buffer[bytesRead] = '\0';
            printf("Child received: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                printf("Child exiting...\n");
                break;
            }
        }

        close(pipefd[0]);  // Close the read end of the pipe
        exit(EXIT_SUCCESS);

    } else {
        close(pipefd[0]);  // Close the read end of the pipe

        // Write messages to the pipe
        const char *messages[] = {"Hello, child!", "exit"};
        for (int i = 0; i < 2; ++i) {
            printf("Parent sending: %s\n", messages[i]);
            ssize_t bytesWritten = write(pipefd[1], messages[i], strlen(messages[i]));

            if (bytesWritten == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            sleep(1);
        }

        close(pipefd[1]);  // Close the write end of the pipe
        wait(NULL);
        printf("Parent exiting...\n");
    }

    return 0;
}
