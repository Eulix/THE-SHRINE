#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "../user/user.h"

// 'argc' is the number of arguments passed from the command line.
// 'argv' is an array of strings representing the arguments.
// 
// In xv6, the OS always sets these 2 values in the stack.
// C's _start function retrieves them from the stack and passes them to our main() function.
// Note that the order of parameters is important. 'int main(char *argv[], int argc)' does not work.
int main(int argc, char *argv[]) {
  // We need 2 arguments:
  //  - argv[0]: the program name. This should always be 'sleep'.
  //  - argv[1]: the number of ticks to sleep.
  if (argc < 2) {
    printf("Usage: sleep ticks\n");
    exit(1);
  }
  int ticks = atoi(argv[1]);
  pause(ticks);
  exit(0);
}
