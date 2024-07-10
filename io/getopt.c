#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

int options = 0;
/*
int main(int argc, char **argv)
{
	int ret;

	while ((ret = getopt(argc, argv, "234")) != -1)
	{
		switch (ret)
		{
		case '2':
			options += 1;
			printf("二阶行列式\n");
			break;
		case '3':
			options += 1;
			printf("三阶行列式\n");
			break;
		case '4':
			options += 1;
			printf("四阶行列式\n");
			break;

		default:
			exit(1);
			break;
		}
	}

	if (options > 1)
	{
		printf("选项太多 只能允许一个选项-2 -3 -4\n");
		exit(1);
	}

	printf("正常退出程序!\n");
	for (int i=optind;i<argc;i++)
		printf("%s\n",argv[i]);

	exit(0);
}
*/

int main(int argc,char** argv){


	

	return 0;
}