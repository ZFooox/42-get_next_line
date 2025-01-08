![Capture d’écran 2025-01-08 à 12 16 48](https://github.com/user-attachments/assets/19d768b8-df04-40a3-b86c-4feb39e85ca4)

# Get Next Line - 42 School Project 🚀

Welcome to **Get Next Line**, a C project developed as part of the 42 School curriculum. This project aims to create a function that reads a line from a file descriptor, one line at a time, handling large files and buffered input effectively. 🎉

## Key Features ✨

**Get Next Line** implements a dynamic function that reads a file descriptor, extracting one line at a time and handling buffer memory efficiently. Here's an overview of the main functions:

### File Reading Functions 📚
- **`get_next_line(int fd)`** - The main function that returns the next line read from the given file descriptor `fd`.
- **`read_and_save(int fd, char *save)`** - Reads the content of a file descriptor into a buffer and saves it for processing.
- **`extract_line(char **save)`** - Extracts a line from the saved data, ensuring that the line is separated correctly and handles the presence of newline characters.

### Helper Functions 🔧
- **`join_and_free(char *save, char *buffer)`** - Concatenates the saved string and the buffer, freeing the old saved string to avoid memory leaks.
- **`save_free_null(char **save)`** - Frees the memory allocated for the saved string and nullifies the pointer to prevent dangling pointers.

### String Utilities 📝
- **`ft_strlen(const char *str)`** - Calculates the length of a string.
- **`ft_strchr(const char *str, int c)`** - Searches for the first occurrence of a character in a string.
- **`ft_strjoin(char *str1, char const *str2)`** - Concatenates two strings into a new string.
- **`ft_strdup(const char *src)`** - Duplicates a given string.
- **`ft_substr(char const *str, unsigned int start, size_t len)`** - Extracts a substring from a given string, starting at the specified index.

## Project Goals 🎯

The goals of this project are to:
- Implement a function that reads a file line by line.
- Ensure efficient memory usage when managing the buffer and file content.
- Follow the 42 coding standards, ensuring code quality and efficiency.
- Understand the mechanics of buffered input and file handling in C.

## Compilation ⚙️

To compile the project, make sure to include the necessary headers and define `BUFFER_SIZE` in your project settings. For example:

```c
#define BUFFER_SIZE 42
```

## Example Usage 📜

Here's an example of how to use the `get_next_line` function in your program:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
## Contributing 🤝

If you want to contribute to this project, feel free to create a pull request. All contributions are welcome! 🎉

Thank you for your interest in my Get Next Line project. If you have any questions or suggestions, feel free to open an issue or contact me! 😊
