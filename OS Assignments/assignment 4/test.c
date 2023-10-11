#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
Author : Pooshpal Baheti PES1UG20CS283
INPUT : Directory and DD MM YYYY.
OUTPUT: FileName : ModificationTime
*/


void main(int argc, char *argv[]) 
{
    DIR *dir;
    struct dirent *entry;  
    if ((dir = opendir(argv[1])) == NULL)
        perror("\nopendir() error");
    else 
    {
        printf("\nContents of %s after : %s/%s/%s",argv[1],argv[2],argv[3],argv[4]);
        while ((entry = readdir(dir)) != NULL)
        {
            char *t = (char *) calloc(100, sizeof(char));
            struct stat b;
            if (!stat(entry->d_name, &b)) 
            {
                strftime(t, 100, "%d/%m/%Y %H:%M:%S", localtime(&b.st_mtime));
                int day = atoi(strtok(t,"/"));
                int month = atoi(strtok(NULL,"/"));
                int year = atoi(strtok(NULL," "));
                int _day = atoi(argv[2]);
                int _month = atoi(argv[3]);
                int _year = atoi(argv[4]);
                if(_year<=year && _month<=month && _day<=day)
                {
                    printf("\nFileName : \"%s\" Last Modified At : %s",entry->d_name,t);
                }
            } 
            else {printf("Error in finding Modification Time\n");}
            
         }
        closedir(dir);
    }
    printf("\n");
    char *host_name = (char *) calloc(100, sizeof(char));
    printf("Logged in as %s\n",getlogin());
    gethostname(host_name, 20);
    printf("on host%s\n",host_name);
}
  
