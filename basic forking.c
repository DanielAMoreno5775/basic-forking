#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main () {
	//variable definitions
	char* name;
	//create a new process and store its PID
	pid_t pid = fork();
	//Handle child process, parent process, and error case in that order
	if (pid == 0) {
		//print the child's and its parent's PIDs
		printf("child: %d started\n", getpid());
		printf("child: parent = %d\n", getppid());
		//put the child to sleep and print messages about this
		printf("child: about to sleep for 20 seconds\n");
		sleep(20);
		printf("child: just woke up\n");
	} else if (pid > 0) {
		//print the parent's and its parent's PIDs
		printf("parent: %d started\n", getpid());
		printf("parent: parent = %d\n", getppid());
	} else {
		//exit with an error
		perror("fork error");
		return -1;
	}
	//If the PID is 0, assign "child" to name; otherwise assign "parent"
	(pid == 0) ? (name = "child") : (name = "parent");
	//print the name of the current process in termination message
	printf("%s: terminating...\n", name);
	return 0;
}