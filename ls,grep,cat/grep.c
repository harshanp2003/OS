#include<stdio.h>
#include<string.h>
void main()
{
    char fname[100],p[100],temp[200];
    FILE *fp;
    printf("Enter the file name\n");
    scanf("%s",fname);
    printf("Enter the pattern to be searched\n");
    scanf("%s",p);
    fp=fopen(fname,"r");
    while(!feof(fp)) //feof means endoffile
    {
        fgets(temp,100,fp); //contents are read from the file and stored in temp array
        if(strstr(temp,p))  //strstr finds and returns the first occurence of the string
            printf("%s",temp);
    }
    fclose(fp);
}