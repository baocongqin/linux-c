#include "apue.h"

#define BUFFERSIZE 1024
#define PINGTIMES  10

int main(int argc, char **argv)
{
	int pipefd[2];

	int ret = pipe(pipefd);

	

	if (ret == -1)
	{
		perror("pipe()");
		exit(1);
	}

	pid_t pid = fork();
	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (pid == 0) // 子进程
	{

		close(pipefd[0]); // 关闭读端 子进程用来写数据
		dup2(pipefd[1],STDOUT_FILENO); //让标准w输出指向管道写端
		execl("/usr/bin/ping", "ping", "127.0.0.1", "-c" ,"10", NULL);
	}

	// 父进程

	while (1)
	{
		char output[BUFFERSIZE] = {0};
		ssize_t nread = read(pipefd[0], output, BUFFERSIZE);  //nread不包括\0
		// output[nread-1] = ' '; //把\n替换成t空格
		// strcat(output,"come from parent process!");
		fputs(output,stdout);
		//检测一下ping是否结束
		if (strstr(output,"rtt min"))
			break;
	}

	puts("exit app!");
	close(pipefd[0]);


	wait(NULL);

	exit(100);
}
