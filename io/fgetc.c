#include <stdio.h>
#include <stdlib.h>

int main(){

    int count = 0;

    FILE* fps = fopen("/etc/passwd","r");


    while(fgetc(fps)!=EOF)
        count++;
    
    printf("count:%d\n",count);

    exit(0);
}