<div align="center">
    <h1>libft</h1>
</div>

<div align="center">
    <h2>DESCRIPTION : </h2>
</div>

This project is one of the main pillar of every other C project of the common core. On this project we have create a [C static library (.a)](https://medium.com/@abhishekjainindore24/static-library-vs-dynamic-library-understanding-the-differences-26e47cac93b6) who contain our version of many [libc](https://en.wikipedia.org/wiki/C_standard_library) standard function. This project must be perfect to avoid to get trouble on the every next C project.

<div align="center">
    <h2>INSTALLATION : </h2>
</div>

- Compile the library
```sh
make
# OR
make bonus
```
- Remove every object files
```sh
make clean
```
- Remove every object files and the compiled library
```sh
make fclean
```

<div align="center">
    <h2>FUNCTION AVAILABLE : </h2>
</div>


| Function | Invocation | Description |
|----------|-----------|-------------|
| **isalpha** | `isalpha(int c)` | Returns **non-zero if the character is alphabetic (a-z, A-Z)**; otherwise returns 0 |
| **isdigit** | `isdigit(int c)` | Returns **non-zero if the character is a digit (0-9)**; otherwise returns 0 |
| **isalnum** | `isalnum(int c)` | Returns **non-zero if the character is alphanumeric (a-z, A-Z, 0-9)**; otherwise returns 0 |
| **isascii** | `isascii(int c)` | Returns **non-zero if the character is ASCII (0-127)**; otherwise returns 0 |
| **isprint** | `isprint(int c)` | Returns **non-zero if the character is printable**; otherwise returns 0 |
| **strlen** | `strlen(const char *str)` | Returns **the length of the string in bytes**, not including the null terminator |
| **memset** | `memset(void *s, int c, size_t n)` | **Fills the first n bytes of memory with the byte value c**; returns pointer to s |
| **bzero** | `bzero(void *s, size_t n)` | **Fills the first n bytes of memory with zeros**; returns void (BSD function) |
| **memcpy** | `memcpy(void *dest, const void *src, size_t n)` | **Copies n bytes from src to dest**; does not check for overlapping memory; returns dest |
| **memmove** | `memmove(void *dest, const void *src, size_t n)` | **Copies n bytes from src to dest** safely even if regions overlap; returns dest |
| **strlcpy** | `strlcpy(char *dest, const char *src, size_t size)` | **Copies src to dest, guaranteeing null termination**; size is the total size of dest; returns length of src (BSD function) |
| **strlcat** | `strlcat(char *dest, const char *src, size_t size)` | **Appends src to dest, guaranteeing null termination**; size is the total size of dest; returns length of dest + src (BSD function) |
| **toupper** | `toupper(int c)` | Returns **the uppercase version of the character if it's lowercase**; otherwise returns c unchanged |
| **tolower** | `tolower(int c)` | Returns **the lowercase version of the character if it's uppercase**; otherwise returns c unchanged |
| **strchr** | `strchr(const char *str, int c)` | Returns **a pointer to the first occurrence of character c in str**; returns NULL if not found |
| **strrchr** | `strrchr(const char *str, int c)` | Returns **a pointer to the last occurrence of character c in str**; returns NULL if not found |
| **strncmp** | `strncmp(const char *s1, const char *s2, size_t n)` | **Compares the first n bytes of two strings**; returns 0 if equal, negative if s1 < s2, positive if s1 > s2 |
| **memchr** | `memchr(const void *s, int c, size_t n)` | Returns **a pointer to the first byte matching c within the first n bytes of s**; returns NULL if not found |
| **memcmp** | `memcmp(const void *s1, const void *s2, size_t n)` | **Compares the first n bytes of two memory areas**; returns 0 if equal, negative if s1 < s2, positive if s1 > s2 |
| **strnstr** | `strnstr(const char *haystack, const char *needle, size_t len)` | Returns **a pointer to the first occurrence of the substring needle in haystack, searching only the first len bytes**; returns NULL if not found (BSD function) |
| **atoi** | `atoi(const char *str)` | **Converts the string str to an integer**; returns the converted value; returns 0 if conversion fails |
| **calloc** | `calloc(size_t nmemb, size_t size)` | **Allocates memory for nmemb elements of size bytes each and initializes all bytes to zero**; returns pointer to allocated memory or NULL on failure; requires `#include <stdlib.h>` |
| **strdup** | `strdup(const char *str)` | **Allocates memory and copies the string str into it, including the null terminator**; returns pointer to the new string or NULL on failure; requires `#include <string.h>` |
| **ft_substr** | `char *ft_substr(char const *s, unsigned int start, size_t len)` | **Allocates memory and returns a substring from s starting at index start with maximum length len**; returns pointer to new string or NULL if allocation fails; requires `malloc()` |
| **ft_strjoin** | `char *ft_strjoin(char const *s1, char const *s2)` | **Allocates memory and returns a new string that concatenates s1 and s2**; returns pointer to new string or NULL if allocation fails; requires `malloc()` |
| **ft_strtrim** | `char *ft_strtrim(char const *s1, char const *set)` | **Allocates memory and returns a copy of s1 with characters from set removed from the beginning and end**; returns pointer to trimmed string or NULL if allocation fails; requires `malloc()` |
| **ft_split** | `char **ft_split(char const *s, char c)` | **Allocates memory and returns a NULL-terminated array of strings created by splitting s using delimiter c**; each string is allocated independently; the array itself is also allocated dynamically; returns NULL if any allocation fails; requires `malloc()` and `free()` |
| **ft_itoa** | `char *ft_itoa(int n)` | **Allocates memory and returns a string representation of the integer n**; handles negative numbers correctly; returns pointer to new string or NULL if allocation fails; requires `malloc()` |
| **ft_strmapi** | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | **Allocates memory and returns a new string created by applying function f to each character of s**; f receives the character's index as first argument and the character itself as second argument; returns pointer to new string or NULL if allocation fails; requires `malloc()` |
| **ft_striteri** | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | **Applies function f to each character of s, passing its index as the first argument**; characters are passed by address to f so they can be modified in place; returns void; requires no external functions |
| **ft_putchar_fd** | `void ft_putchar_fd(char c, int fd)` | **Outputs character c to the file descriptor fd**; returns void; requires `write()` |
| **ft_putstr_fd** | `void ft_putstr_fd(char *s, int fd)` | **Outputs string s to the file descriptor fd**; returns void; requires `write()` |
| **ft_putendl_fd** | `void ft_putendl_fd(char *s, int fd)` | **Outputs string s to the file descriptor fd followed by a newline character**; returns void; requires `write()` |
| **ft_putnbr_fd** | `void ft_putnbr_fd(int n, int fd)` | **Outputs integer n to the file descriptor fd**; returns void; requires `write()` |
| **ft_lstnew** | `t_list *ft_lstnew(void *content)` | **Allocates memory and creates a new node with the given content**; initializes the content member variable with the parameter; sets next to NULL; returns pointer to new node or NULL if allocation fails; requires `malloc()` |
| **ft_lstadd_front** | `void ft_lstadd_front(t_list **lst, t_list *new)` | **Adds the node new at the beginning of the list**; updates the list pointer to point to the new node; returns void; requires no external functions |
| **ft_lstsize** | `int ft_lstsize(t_list *lst)` | **Counts and returns the number of nodes in the list**; returns the length as an integer; requires no external functions |
| **ft_lstlast** | `t_list *ft_lstlast(t_list *lst)` | **Returns a pointer to the last node of the list**; traverses the list by following next pointers until reaching a node with next == NULL; requires no external functions |
| **ft_lstadd_back** | `void ft_lstadd_back(t_list **lst, t_list *new)` | **Adds the node new at the end of the list**; finds the last node and appends new to it; returns void; requires no external functions |
| **ft_lstdelone** | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | **Frees the content of node lst using the del function, then frees the node itself**; does NOT free the next node; returns void; requires `free()` |
| **ft_lstclear** | `void ft_lstclear(t_list **lst, void (*del)(void *))` | **Deletes and frees the given node and all successor nodes using the del function**; iterates through entire list freeing each node's content and the node itself; sets the list pointer to NULL; returns void; requires `free()` |
| **ft_lstiter** | `void ft_lstiter(t_list *lst, void (*f)(void *))` | **Iterates through the list and applies function f to the content of each node**; f receives the node's content as parameter; does not create a new list; returns void; requires no external functions |
| **ft_lstmap** | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | **Iterates through list lst, applies function f to each node's content, and creates a new list from the results**; f transforms each node's content; del is used to delete content if allocation fails; returns pointer to new list or NULL if allocation fails; requires `malloc()` and `free()` |

<div align="center">
    <h2>SKILL GAIN : </h2>
</div>

- Review and reinforced every C basis learn during the 42 piscine
- Have learn what is a linked list and how to use it
