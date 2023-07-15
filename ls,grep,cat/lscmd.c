#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
void main(int argc,char *argv[])//argc stores the number of command line arguments passed,argv stores the command line arguments
{
    DIR *dp;//DIR is adirectory stream 
    struct dirent *dirp;//dirent structure represents an entry in a directory
    if(argc<2)
    {
        printf("\n you are not passing the directory\n");
        exit(1);

    }
    if((dp=opendir(argv[1]))==NULL)
    {
        printf("\nCannot open it it does not exixt %s file\n",argv[1]);
        exit(1);
    }
    while((dirp=readdir(dp))!=NULL)
         printf("%s\n",dirp->d_name);
    closedir(dp);
}