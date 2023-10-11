#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    int x = strtol(argv[1], 0, 0);
    int y = strtol(argv[2], 0, 0);
    printf("%d",x+y);
    return 0;
}

