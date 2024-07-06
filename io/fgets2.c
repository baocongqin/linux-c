#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 256
int main(int argc, char **argv)
{

	/*
		char buf[BUFFERSIZE];
	while (1)
	{
		fgets(buf, BUFFERSIZE, stdin);
		fputs(buf, stdout);
		printf("\n");
	}


	*/

	// fgets read file
	FILE* fp = fopen(argv[1],"r");

	char buf[BUFFERSIZE];
	while(fgets(buf,BUFFERSIZE,fp)!=NULL)
		fputs(buf,stdout);
	
	fclose(fp);
	exit(0);
}
