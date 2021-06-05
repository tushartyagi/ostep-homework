#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  int first_rc = fork();
  
  if (first_rc < 0) {
    printf("Fork failed, go home");
    exit(2);
  } else  if (first_rc == 0) { // child process
    int i;
    for (i = 0; i < 5; ++i) {
      printf("%d: sleeping\n", getpid());
      sleep(1);
    }
    exit(1);
  } else {
    printf("First child (pid: %d)\n", first_rc);
    int second_rc = fork();

    if (second_rc == 0) { // second child
      int i;
      for (i = 0; i < 3; ++i) {
        printf("%d: sleeping\n", getpid());
        sleep(1);
      }
      exit(2);
    }
    else {
      printf("Second child (pid: %d)\n", second_rc);

      int child_status;
      int child_pid = wait(&child_status);
      printf("Child (pid: %d) ended with state: %d\n", child_pid, child_status);

      printf("Waiting for the other child\n");
      int second_child_pid = waitpid(first_rc, &child_status, 0);
      printf("Child (pid: %d) ended with state: %d\n", second_child_pid, child_status);
      
      printf("Ending\n");
    }
  }

  return 0;
}
