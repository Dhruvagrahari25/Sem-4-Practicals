#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int wait_func()
{
  int pid_1 = fork();
  if (pid_1 == 0){
    printf("Process pid_1 successfully created\n");
    printf("Process pid_1 id: %d\n", getpid());
    exit(0);
  }
  waitpid(pid_1, NULL, 0);
  printf("pid_1 process terminated.\n");
  return 0;
}
int main()
{
  int pid = fork();
  if (pid == 0){
    printf("Child process created\n");
    printf("Current child is: %d\n", getppid());
    printf("Current parent is: %d\n", getpid());
    exit(0);
  }
  wait(NULL);
  printf("Child process is terminated.\n");
  wait_func();
  return 0;
}
