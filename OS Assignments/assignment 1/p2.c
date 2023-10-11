#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int a[8] = {1,6,2,4,5,8,9,0};

int main()
{
	pid_t p1;
	p1 = fork();
	
	if(p1==0)
	{

	    int ele,i,j;
	    for(i=1; i<8; i++)
	    {
		ele = a[i];
		j = i-1;
		while(j>=0 && a[j]>ele)
		{
		    a[j+1] = a[j];
		    j--;
		}
		a[j+1] = ele;
	    }
	    

	}

	if(p1>0)
	{
	
		sleep(5);
		for(int i=0; i<8; i++)
		{
			printf("%d\t",a[i]);
		}
			
	}
}