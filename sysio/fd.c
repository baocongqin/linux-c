#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FILEPATH "/etc/passwd"
/*
	标准IO与文件IO
	r = O_RDONLY
	r+ =O_RDWR
	w  = WRONLY|O_CREATE
	w+ = O_RDWR|O_CREATE|O_TRUNC

*/
int main(int argc,char** argv){

	
	int fd1,fd2,fd3;
	close(STDIN_FILENO);
	FILE *fp = fopen(FILEPATH,"r");
	fd1 = open(FILEPATH,O_RDONLY);
	fd2 = open(FILEPATH,O_RDONLY);
	fd3 = open(FILEPATH,O_RDONLY);

	printf("fd1:%d fd2:%d fd3:%d \n",fd1,fd2,fd3);

	fclose(fp);
	close(fd1);
	close(fd2);
	close(fd3);


	exit(0);
}
