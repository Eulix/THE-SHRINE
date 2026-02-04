#include "../kernel/fcntl.h"
#include "../kernel/types.h"
#include "../user/user.h"

void memdump(char *fmt, char *data);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Professor's code removed because we don't own it.\n");
    exit(1);
  } else if (argc == 2) {
    // statically allocate 1000 bytes
    char data[1000];
    int bytes_read = 0;
    // Read stdin into 'data'
    memset(data, '\0', sizeof(data));
    while (bytes_read < sizeof(data)) {
      int actually_read = read(
          0,                         // stdin's fd is 0
          data + bytes_read,         // start writing here
          sizeof(data) - bytes_read  // read at most this many bytes
      );
      // 0 indicates EOF (end of file)
      // Negative value indicates error
      if (actually_read <= 0)
        break;
      bytes_read += actually_read;
    }
    memdump(argv[1], data);
  } else {
    printf("Usage: memdump [format]\n");
    exit(1);
  }
  exit(0);
}

void memdump(char *fmt, char *data) {
  // For each character in fmt, we:
  //  1. Cast data to the specified pointer type
  //  2. Dereference the pointer to print the value
  //  3. Advance data by the size of the type
  for (; *fmt != 0; fmt++) {
    switch (*fmt) {
    case 'i': {
      printf("%d\n", *(int *)data);
      data += sizeof(int);
      break;
    }
    case 'p': {
      printf("%lx\n", *(unsigned long *)data);
      data += sizeof(unsigned long);
      break;
    }
    case 'h': {
      printf("%d\n", *(short *)data);
      data += sizeof(short);
      break;
    }
    case 'c': {
      printf("%c\n", *(char *)data);
      data += sizeof(char);
      break;
    }
    case 's': {
      // Note that data is a pointer to a string, so we use char** instead of char*
      printf("%s\n", *(char **)data);
      data += sizeof(char *);
      break;
    }
    case 'S': {
      // The string is stored directly inside data, so we don't dereference anything
      printf("%s\n", (char *)data);
      data += strlen(data) + 1; // Add 1 for the null terminator
      break;
    }
    }
  }
}
