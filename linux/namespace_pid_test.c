#define _GNU_SOURCE
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main_function(void *arg)
{
	printf("CHILD: pid=%d, ppid=%d\n", getpid(), getppid());
	sleep(1000);
	return 0;
}


int main()
{
	void* stack = malloc(1024*1024); // 为子线程分配堆栈空间
	if (stack == NULL) {
		perror("malloc");
		exit(1);
	}	
	printf("IN main: pid=%d, ppid=%d\n", getpid(), getppid());
	int pid = clone(main_function, stack + 1024 * 1024, CLONE_NEWPID, NULL);
	//int pid = clone(main_function, stack + 1024 * 1024, 0, NULL);
	if (pid < 0) {
		perror("clone");
		return 0;
	}
	printf("create new process, pid:%d\n", pid);
/*
    // do not need waitpid, the parent pid 
	pid = waitpid(pid, NULL, 0);
	if(pid < 0) {
		perror("waitpid");
	}
	printf("waitpid return %d\n", pid);
*/
	sleep(1000);
	free(stack);
	return 0;
}

