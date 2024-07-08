#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
	标准IO与文件IO
	r = O_RDONLY
	r+ =O_RDWR
	w  = WRONLY|O_CREATE
	w+ = O_RDWR|O_CREATE|O_TRUNC


*/

int main(int argc, char **argv)
{


	close(STDOUT_FILENO);

	int fd = open("./test",O_RDWR|O_CREAT|O_TRUNC,0600);

	if (fd==-1){

		perror("open");
		exit(1);
	}

	
	fprintf(stdout,"hello world!!!\n");

	close(fd);

	exit(0);
}
