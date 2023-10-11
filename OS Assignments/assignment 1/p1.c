#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t p1;
	p1 = fork();
	
    if(p1==0)
	{
		execl("/bin/ls","ls","-l");
	}
	if(p1>0)
	{
		wait(NULL);
	}
}