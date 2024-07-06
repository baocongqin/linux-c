#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char** argv){

    int count = 0;

    if (argc < 2){

        printf("usage:%s file\n",argv[0]);
        exit(1);
    }


    FILE* fps = fopen(argv[1],"r");

    if (fps ==  NULL)
    {
        perror("fopen");
        exit(1);
    }

    char buf[3];
    while(fgets(buf,2,fps)!=NULL)
        count++;
   
    
    printf("count:%d\n",count);

    exit(0);
}