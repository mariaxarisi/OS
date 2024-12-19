#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	for(int i=0; i<3; i++){
		pid_t pid = fork();
		if(pid == 0){
			printf("Child process created. PID: %d, Parrent PID: %d\n", getpid(), getppid());
			return 0;
		}
		else if(pid > 0){
			printf("Parrent process. PID: %d created child with PID: %d\n", getpid(), pid);
		}
		else{
			perror("fork");
			return 1;
		}
	}

	for(int i=0; i<3; i++){
		wait(NULL);
	}

	return 0;

}
