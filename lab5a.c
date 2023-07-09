//Program to execute exit,execlp system call etc
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() 
{
pid_t child_id,my_id,parent_id,wid;
int i = 10;
child_id = fork();
if (child_id < 0) //After creating a child by the fork process if succesful then 1 is returned to parent and zero to child
{
printf("Fork failed. Exiting!\n");
exit(0);
}
if (child_id == 0) 
{
// Child process
  //printf("[CHILD] Before using exit syscall\n");
  //exit(0);
  printf("[CHILD] This is the child process.\n");
  my_id = getpid();
  parent_id = getppid();
  printf("[CHILD] My pid is %d\n", my_id);
  printf("[CHILD] My parent's pid is %d\n", parent_id);
  printf("[CHILD] i= %d\n",--i);
  printf("[CHILD] Child process going to load another program using execlp syscall\n");//execlp to switch between process
  execlp("/bin/pwd", "pwd", NULL);
} 
else 
{
  // Parent process
    printf("[PARENT] This is the parent process.\n");
  my_id = getpid();
  parent_id = getppid();
  printf("[PARENT] My pid is %d\n", my_id);
  printf("[PARENT] Waiting for child to terminate\n");
  wid=wait(NULL);
  printf("[PARENT] Resuming after the termination of %d\n", wid);
  printf("[PARENT] My parent's pid is %d\n", parent_id);
  printf("[PARENT] My child's pid is %d\n", child_id);
   printf("[PARENT] i= %d\n",++i);
}
return 0;
}
