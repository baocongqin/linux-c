#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char** argv){

    int count = 0;

    if (argc < 3){

        printf("usage:%s srcfile dstfile\n",argv[0]);
        exit(1);
    }


    FILE* fps = fopen(argv[1],"r");
   

    if (fps ==  NULL)
    {
        perror("fopen");
        exit(1);
    }

     FILE* fpd = fopen(argv[2],"w");

     if (fpd ==  NULL)
    {
        fclose(fps);
        perror("fopen");
        exit(1);
    }

    while(1){
        int ch = fgetc(fps);
        if (ch==EOF)
            break;
        fputc(ch,fpd);

    }
    
    fclose(fpd);
    fclose(fps);
    

    exit(0);
}