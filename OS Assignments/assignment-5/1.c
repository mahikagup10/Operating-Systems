//c program to truncate files in a directory created after a certain date to half its original size.
//i/p - directory and date as runtime args

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#define _POSIX1_SOURCE 2
#include <unistd.h>
#define string_len 1000
#define _XOPEN_SOURCE_EXTENDED 1

int truncate(const char *path, off_t length);

//int ftruncate(int fildes, off_t length);

int main(int argc, char* argv[])
{
    char ch;
    const char *name = "Arbitrary-Directory2";
    mkdir(name, S_IRWXU);
    struct dirent *de;  // Pointer for directory entry
    struct stat b;
   
    //strcpy(path,"/Users/mahika/4th sem/OS LAB");
    DIR *dr = opendir(argv[1]);

    stat(argv[1], &b);
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
    
    char* date[3];
    char* token = strtok(argv[2], "/");
    int i=0;

    while (token != NULL) {
        date[i] = token;
        printf("%s\n", token);
        token = strtok(NULL, "/");
        i++;
    }
    
    printf("\nContents of %s after :",argv[1]);
    for(int i=0; i<3; i++)
        printf("%s/",date[i]);


    while ((de = readdir(dr)) != NULL)
    {
        char *t = (char *) calloc(100, sizeof(char));
            struct stat b;
            if (!stat(de->d_name, &b)) 
            {
                
                strftime(t, 100, "%d/%m/%Y %H:%M:%S", localtime(&b.st_mtime));
                int day = atoi(strtok(t,"/"));
                int month = atoi(strtok(NULL,"/"));
                int year = atoi(strtok(NULL," "));
                int _day = atoi(date[2]);
                int _month = atoi(date[1]);
                int _year = atoi(date[0]);
                if(_year<=year && _month<=month && _day<=day)
                {
                    strcat(argv[1],"/");
                    strcat(argv[1],de->d_name);
                    int length = b.st_size;
                    truncate(argv[1],length/2);
                }
                printf("\nSize of truncated file:%lld",b.st_size);
            } 
            else {printf("Error in finding Modification Time\n");}
            
    }
        closedir(dr);
    return 0;
}