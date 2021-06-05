#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

  if (argc != 2) {
    printf("usage: q4 <num>\n");
    printf("where: num is any number from 1 to 6\n");
    exit(1);
  }
  char *error;
  int num = strtol(argv[1], &error, 10);

  if (num < 1 || num > 6) {
    printf("Can't really deal with you\n");
    exit(1);    
  } else {
    printf("You chose: %d\n", num);
  }
  

  int rc = fork();
  
  if (rc < 0) {
    printf("Fork failed, go home");
    exit(2);
  } else  if (rc == 0) { // child process
    switch(num) {
    case 1:
      printf("Running execl\n");
      execl("/bin/ls", ".");
    case 2:
      printf("Running execle\n");
      // Changing the home here and passing it in the environment
      char *env1[2] = { "HOME=/Users/", NULL};
      execle("/bin/ls", "/bin/ls", "-a", "-l", NULL, env1);
      break;
    case 3:
      printf("Running execlp\n");
      char *env2[2] = { "PATH=/usr/bin", NULL};
      execlp("ls", "ls", "-l", NULL, env2);
      break;        
    }

  }
  
  
  
  return 0;
}
