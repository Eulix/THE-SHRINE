#include "../kernel/param.h"
#include "../kernel/types.h"
#include "../user/user.h"

// reads the next whitespace-delimited argument from stdin into buf.
// returns pointer to buf, or 0 if no more args.
char *get_arg(char *buf) {
  char *write_head = buf;
  // Remember, 0 is stdin's fd
  while (read(0, write_head, 1) > 0) {
    if (*write_head == ' ' || *write_head == '\n') {
      if (write_head == buf) {
        // trim leading whitespace
        continue;
      }
      break;
    }
    write_head++;
  }
  // Empty string, return null
  if (write_head == buf) {
    return 0;
  }

  *write_head = '\0'; // don't forget to null-terminate
  return buf;
}

int main(int argc, char *argv[]) {
  int max_args = MAXARG;
  // Check for -n option
  if (argc > 2 && strcmp("-n", argv[1]) == 0) {
    max_args = atoi(argv[2]);
    // Skip '-n' and the number after it
    argc -= 2;
    argv += 2;
  }

  // statically allocate args array
  char *args[MAXARG + 1]; // +1 for null terminator
  memset(args, 0, sizeof(args));
  // Copy initial args from command line
  for (int i = 1; i < argc; i++) {
    args[i - 1] = argv[i];
  }

  // buffer for holding all args from stdin.
  // assume combined length is never more than 1000 btyes. 
  char stdin_buf[1000];
  while (1) {
    char *write_head = stdin_buf;
    int i = 0;
    for (; i < max_args; i++) {
      char *arg = get_arg(write_head);
      if (arg == 0) {
        // no more args
        break;
      }
      write_head += strlen(arg) + 1; // +1 for null terminator
      args[argc - 1 + i] = arg; // place arg in args array
    }
    if (i == 0) {
      // No more args
      break;
    }
    args[argc - 1 + i] = 0; // args array must also be null-terminated

    // fork and exec to run the command
    int pid = fork();
    if (pid == 0) {
      // when pid == 0, we are the child.
      exec(args[0], args); // The first param is the executable name, which is already in our args array.
      exit(0);
    } else if (pid > 0) {
      // when pid > 0, we are the parent.
      wait(0);
    } else {
      // pid < 0 is an error.
      fprintf(2, "Failed to fork.\n");
      exit(1);
    }
  }
  exit(0);
}
