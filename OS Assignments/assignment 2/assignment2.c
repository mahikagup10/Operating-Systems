//Implement pipe operator in C with the following functionality 
// -The parent process reads in a file "input.txt" and redirects the output to the pipe 
// -The child process must read the contents of the file and perform a word count

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 40
#define READ_END 0
#define WRITE_END 1

int main()
{
    char c[] = "this is the text in input file";
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE] = "";
    //char c;
	int fd[2];
	pid_t  pid;

	if (pipe(fd) == -1) 
	{
		printf("Pipe failed\n");
		return 1;
	}

	pid = fork();

	if (pid > 0)  
	{	
        FILE* fp = fopen("/Users/mahika/4th sem/OS LAB/assignment 2/input.txt", "w+");
        fwrite(c, strlen(c) + 1, 1, fp);
        fseek(fp, 0, SEEK_SET);
        fread(write_msg, strlen(c)+1, 1, fp);
        fclose(fp);

		close(fd[READ_END]);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
        close(fd[WRITE_END]);

		wait(NULL);
	}

	else if (pid == 0) 
	{   
        int count;

		close(fd[WRITE_END]);
		read(fd[READ_END], read_msg, BUFFER_SIZE);

		printf("child process read -%s\n", read_msg);

        for (int i = 0; read_msg[i] != '\0'; i++)
        {
            if (read_msg[i] == ' ' && read_msg[i+1] != ' ')
                count++;    
        }
        printf("Number of words read by child process: %d\n", count + 1);

		close(fd[READ_END]);
	}
	else 
	{ 
		printf("Fork failed\n");
		return 1;
	}

}
