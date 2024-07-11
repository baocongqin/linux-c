#include "apue.h"

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
		// 开 始写数据
		for (int i = 0; i < 10; i++)
		{
			char buf[100] = {0};
			sprintf(buf, "hello world %d\n", i);
			write(pipefd[1], buf, strlen(buf));
			sleep(1);
		}

		write(pipefd[1],"quit",4);
		close(pipefd[1]);
		printf("子进程退出!\n");
		exit(200);
	}

	// 父进程

	while (1)
	{
		char output[100] = {0};
		read(pipefd[0], output, 100);
		if (!strcmp(output,"quit"))
			break;
		puts(output);
	}

	puts("exit app!");
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);

	exit(100);
}
