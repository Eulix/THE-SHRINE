#include "../kernel/types.h"
#include "../user/user.h"
#include "../kernel/fcntl.h"

// C doesn't have a boolean type, so we emulate it with ints
#define BOOL int
#define TRUE 1
#define FALSE 0

// We use this function to skip past separator characters
// Reference: https://en.cppreference.com/w/c/string/byte/strspn
int strspn(const char *dest, const char* src) {
    int i;
    for (i = 0; dest[i]; i++) {
        int found = FALSE;
        for (int j = 0; src[j]; j++) {
            if (dest[i] == src[j]) {
                found = TRUE;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return i;
}

// Returns whether the string is a number divisible by 5 or 6.
// If true, the number is stored in the num pointer.
BOOL isSixFive(const char *s, int* num) {
    // Check if empty
    if (*s == '\0') {
      return FALSE;
    }
    // Check if all characters are digits
    for (int i = 0; s[i]; i++) {
      if (s[i] < '0' || s[i] > '9') {
        return FALSE;
      }
    }
    
    // Parse the number
    *num = atoi(s);
    return ((*num % 5) == 0) || ((*num % 6) == 0);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: sixfive FILES...\n");
    exit(1);
  }
   
  // It's the same process for each file, so we just loop through them 
  for (int i = 1; i <= argc; i++) {
    // open the file for reading
    const char *filename = argv[i];
    int fd = open(filename, O_RDONLY);

    char *seps = " -\r\t\n./,";
    int num;
    char buf[21]; // a 64 bit int has at most 20 digits + null terminator
    memset(buf, 0, sizeof(buf));
    char *write_head = buf;
    while (TRUE) {
      // Read the next character into our buffer
      if (read(fd, write_head, 1) <= 0) {
        // Failed to read, we probably reached EOF
        if (isSixFive(buf, &num)) {
          printf("%d\n", num);
        }
        break;
      }

      if (strspn(write_head, seps) == 0) {
        // The new character was not a separator, read the next character
        write_head++;
        continue;
      }

      // we reached a separator, check for sixfive and print
      *write_head = '\0'; // Remove the separator
      if (isSixFive(buf, &num)) {
        printf("%d\n", num);
      }
      
      // Reset the buffer and write head
      memset(buf, 0, sizeof(buf));
      write_head = buf;
    }
    // Don't forget to close the file!
    close(fd);
  }

  return 0;
}
