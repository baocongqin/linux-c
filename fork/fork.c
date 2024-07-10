#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char** argv){


	printf("[%d] begin\n",getpid());


	pid_t pid = fork();

	if (pid < 0){
		perror("fork");
		exit(1);
	}
	else if(pid == 0)
	{

		//子进程 工作区
		printf("[%d]子进程工作中...\n",getpid());


	}
	else  //pid > 0
	{
		//父进程 工作区
		printf("[%d] 父进程工作中...\n",getpid());
		// getchar();

	}



	printf("[%d] end\n",getpid());



	exit(0);
}
