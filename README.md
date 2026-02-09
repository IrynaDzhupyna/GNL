*This project has been created as part of the 42 curriculum by irdzhupy*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns a single line from a file descriptor each time it is called.  
The returned line includes the terminating newline character (`\n`) if one is present, or the remaining content at end-of-file.

The main goal of this project is to deepen understanding of:
- Static variables
- File descriptor handling
- Memory management
- Buffered reading using the `read()` system call

This implementation strictly follows the constraints and coding standards defined by the 42 curriculum.

---

## Instructions

### Compilation

This project is meant to be compiled together with your own test file.

Example:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

If `BUFFER_SIZE` is not defined at compile time, it defaults to `1`.

---

### Usage

Example `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Each call to `get_next_line()` returns:
- The next line from the file descriptor
- `NULL` when there is nothing left to read or on error

---

## Algorithm

### Overview

This implementation uses a **static buffer (`stash`)** to store unread data between function calls.  
The algorithm reads from the file descriptor until a newline character is found or EOF is reached.

The process is divided into clear steps using small helper functions.

---

### Step-by-step Logic

1. **Persistent storage (`stash`)**
   - A static `char *stash` keeps leftover data between calls.
   - It is initialized once as an empty string.

2. **Reading from the file descriptor**
   - The function checks if a newline already exists in `stash`.
   - If not, it reads more data from the file descriptor.

3. **Buffered reading and concatenation**
   - Data is read in chunks of size `BUFFER_SIZE`
   - Each chunk is appended to `stash`
   - Reading stops once a newline is found or EOF is reached

4. **Extracting the line**
   - The line up to and including `\n` is extracted
   - If no newline exists, the remaining content is returned

5. **Cleaning the stash**
   - Used data is removed from `stash`
   - If nothing remains, `stash` is freed

---

### Justification of the Algorithm

- **Static variable**  
  Required to preserve unread data between calls without using global variables.

- **Dynamic buffer size**  
  Works with any `BUFFER_SIZE`, including very small values.

- **Memory safety**
  - Every allocation has a corresponding `free`
  - Read errors are handled safely
  - No memory leaks at EOF

- **Efficiency**
  - Reading stops as soon as a full line is available
  - Avoids unnecessary system calls

---

## Resources

### References
- man 2 read
- man 3 malloc
- man 3 free
- 42 subject PDF: *get_next_line*

### AI Usage

AI was used only as a learning and support tool for:
- Understanding edge cases
- Reviewing memory management
- Clarifying algorithm structure

All code was written, tested, and debugged manually by the author.

---

## Notes

- Bonus part (multiple file descriptors) is not implemented
- The code follows the 42 Norm and subject constraints
