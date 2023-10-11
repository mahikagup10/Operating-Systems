#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char **argv)
{
    pid_t p1;
    p1 = fork();
    // int x,y;
    // printf("Enter 2 integers: ");
    // scanf("%d\n%d",&x,&y);

    if(p1==0)
    {
        static char *args[] = { "./sum", "4", "5", NULL };
        execv(args[0],args);
    }
    return 0;


}


