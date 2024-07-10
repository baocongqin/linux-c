#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 90
#define NUM 51 
#define WW O_RDWR|O_CREAT|O_TRUNC

int main(int argc, char **argv)
{
	pid_t pid;
	int i;
	int fd = open("hello.txt",WW,0600) ;
	for (i = 0; i < N; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{

			// 子进程 工作区
			// sleep(1);
			lseek(fd,i*NUM,SEEK_SET);
			char buf[NUM];
			memset(buf,i+'!',NUM);
			buf[NUM-1]='\n';
			write(fd,buf,NUM);
			close(fd);
			//子进程退出
			exit(1);
		}
	}

	//只剩下父进程
	wait(NULL);
	close(fd);

	exit(0);
}
