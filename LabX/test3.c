#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigusr1_handler(int sig) {
    printf("Child received SIGUSR1\n");
}

int main() {
    pid_t pid = fork();

    if(pid == 0){
        if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }
        printf("Child waiting for signal...\n");
        pause();
    }
    else if(pid > 0){
        sleep(2);
        printf("Parent sending SIGUSR1 to child\n");
        if (kill(pid, SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
	wait(NULL);
    }
    else{
	perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
