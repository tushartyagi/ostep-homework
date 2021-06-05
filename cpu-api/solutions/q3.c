#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  // Set the value which is going to be accessed in the child process
  int rc = fork();

  // Fork failed, go home
  if (rc < -1) {
    fprintf(stderr, "Cannot fork. Go home");
    exit(1);    
  } else if (rc == 0) { // child process
    printf("child: hello\n");
  } else { // this process
    // sleep(1); // This works for sure
    int fd = open("q3.c", O_RDONLY);
    printf("parent: goodbye\n");
  }  

  return 0;
}
