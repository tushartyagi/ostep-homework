#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  int rc = fork();
  
  if (rc < 0) {
    printf("Fork failed, go home");
    exit(2);
  } else  if (rc == 0) { // child process
    int i;
    for (i = 0; i < 5; ++i) {
      printf("sleeping\n");
      sleep(1);
    }
    exit(1);
  } else {
    printf("Waiting for the kid (pid: %d)\n", rc);
    int child_status;
    int child_pid = wait(&child_status);

    printf("Child (pid: %d) ended with state: %d\n", child_pid, child_status);    
    printf("Ending\n");
  }

  return 0;
}
