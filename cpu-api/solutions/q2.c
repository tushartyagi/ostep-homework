#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  // Set the value which is going to be accessed in the child process
  int fd = open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  int rc = fork();

  // Fork failed, go home
  if (rc < -1) {
    fprintf(stderr, "Cannot fork. Go home");
    exit(1);    
  } else if (rc == 0) { // child process
    char* child_write = "love from child\n";
    printf("child: I'll try to write something on the file\n");
    // Need to find a better way that just putting in a magic number here
    write(fd, child_write, 17);
    printf("child: I've written\n");
  } else { // this process
    char* parent_write = "love from parent\n";
    printf("parent: I'll try to write something on the file\n");
    write(fd, parent_write, 17);
    printf("parent: I've written\n");
  }  

  return 0;
}
