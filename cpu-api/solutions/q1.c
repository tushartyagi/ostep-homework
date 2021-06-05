#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  // Set the value which is going to be accessed in the child process
  int x = 100;
  int rc = fork();

  // Fork failed, go home
  if (rc < -1) {
    fprintf(stderr, "Cannot fork. Go home");
    exit(1);    
  } else if (rc == 0) { // child process
    printf("child: Since I get all the heap and local state from the parent\n");
    printf("child: I should be getting the variable x: %d\n", x);
    x += 123;
    printf("child: And I changed it to something else: %d\n", x);
  } else { // this process
    //int rc_wait = wait(NULL);
    printf("parent: I too have access to the variable x: %d\n", x);
    printf("parent: Although it hasn't changed.\n");
    sleep(1);
    printf("parent: so I'll change it now: %d.\n", ++x);
    
  }  

  return 0;
}
