#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(void)
{
    struct dirent *de;  // Pointer for directory entry
    struct stat attr;

    char path[1000];
   
    strcpy(path,"/Users/mahika/4th sem/OS LAB");
    DIR *dr = opendir(path);

    stat(path, &attr);
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
 
    while ((de = readdir(dr)) != NULL)
    {
        printf("Time of creation: %s", ctime(&attr.st_birthtime));
        printf("%s\n", de->d_name);
    }

    closedir(dr);    
    return 0;
}

