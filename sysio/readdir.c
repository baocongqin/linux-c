#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc,char** argv){

	DIR* pdir = opendir("/etc");
	
	while(1)
	{
		struct dirent *nextent = readdir(pdir);
		if (nextent==NULL)
			break;

		fprintf(stdout,"%s\n",nextent->d_name);

	}
	




	exit(0);
}
