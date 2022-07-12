/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonna <fdonna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:23:30 by fdonna            #+#    #+#             */
/*   Updated: 2021/10/06 18:23:30 by fdonna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef unsigned long long	t_size;

/* ************************************************************************** */
/* ************************ PART I - LIBC Functions ************************* */
/* ************************************************************************** */

/**
 * @brief Checks for an alphabetic character; in the standard "C"
 * locale, it is equivalent to (isupper(c) || islower(c)).
 * In some locales, there may be additional characters for
 * which isalpha() is true—letters which are neither uppercasenor lowercase.
 *
 * @param c The character to check.
 * @return Function returns 1024 if 'c' is alphabetical, otherwise 0.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks for digit (0 through 9).
 *
 * @param c The character to check.
 * @return Function returns 2048 if 'c' is digit, otherwise returns 0.
 */
int			ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character,
 * it is equivalent to (isalpha(c) || isdigit(c)).
 *
 * @param c The character to check.
 * @return Function returns 8 if 'c' is alphabetical or digit,
 * otherwise returns 0.
 */
int			ft_isalnum(int c);

/**
 * @brief Checks whether 'c' is a 7-bit unsigned char value that fits
 * into the ASCII character set.
 *
 * @param c The character to check.
 * @return Function returns 1 if 'c' < 0x80, otherwise returns 0.
 */
int			ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 *
 * @param c The character to check.
 * @return Function returns 16384 if 'c' is printable ascii character,
 * otherwise returns 0.
 */
int			ft_isprint(int c);

/**
 * @brief Calculate the lenght of a string.
 *
 * @param s The string to which length to calculate.
 * @return Function returns the length of the string 's'.
 */
t_size		ft_strlen(const char *s);

/**
 * @brief Function erases the data in the n bytes of the
 * memory starting at the location pointed to by s, by
 * writing zeros (bytes containing '\0') to that area.
 *
 * @param s The location to start from.
 * @param n The number of bytes to zero.
 */
void		ft_bzero(void *s, t_size n);

/**
 * @brief Function fills the first n bytes of the memory
 * area pointed to by s with the constant byte c.
 *
 * @param s The pointer to the memory block.
 * @param c The byte to fill memory with.
 * @param n The number of bytes to fill from memory block start.
 * @return Function returns memory block pointed by 's'.
 */
void		*ft_memset(void *s, int c, t_size n);

/**
 * @brief Function copies n bytes from memory area src to memory
 * area dest. The memory areas must not overlap.
 * Use ft_memmove if memory areas do overlap.
 *
 * @param dest The memory area to copy to.
 * @param src The memory area to copy from.
 * @param n The number of bytes to copy.
 * @return Function returns a pointer to 'dest'.
 */
void		*ft_memcpy(void *dest, const void *src, t_size n);

/**
 * @brief Function copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap: copying takes place as though the bytes in src
 * are first copied into a temporary array that does not overlap src or dest,
 * and the bytes are then copied from the temporary array to dest.
 *
 * @param dest The momory to copy move to.
 * @param src The memory area to copy from.
 * @param n The number of bytes to copy.
 * @return Function returns a pointer to 'dest'
 */
void		*ft_memmove(void *dest, const void *src, t_size n);

/**
 * @brief Function scans the initial n bytes of the memory area pointed
 * to by s for the first instance of c. Both c and the bytes of
 * the memory area pointed to by s are interpreted as unsigned char.
 *
 * @param s The pointer to the memory area to scan from.
 * @param c The byte to search.
 * @param n The number of bytes to scan.
 * @return Functions return a pointer to the matching byte or NULL
 * if the character does not occur in the given memory area.
 */
void		*ft_memchr(const void *s, int c, t_size n); // TODO: Improve

/**
 * @brief Function copy the source string to the destination string.
 *
 * @param dest The pointer to the destination string.
 * @param src The pointer to the source string.
 * @param n The numer of bytes to copy.
 * @return Functioin returns the total length of the source string.
 */
t_size		ft_strlcpy(char *dest, const char *src, t_size n);

/**
 * @brief Function concatenate the destination string with the source string.
 *
 * @param dest The pointer to a string to append characters.
 * @param src The pointer to a string to copy characters from.
 * @param n The number of bytes to append.
 * @return Function returns the inital length of a destination
 * string plus the length of a source string.
 */
t_size		ft_strlcat(char *dest, const char *src, t_size n);

/**
 * @param s The pointer to the first character.
 * @param c The character to search.
 * @return Function returns a pointer to the first occurrence of the
 * character c in the string s.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @param s The pointer to the first character.
 * @param c The character to search.
 * @return Function returns a pointer to the last occurrence of the character
 * c in the string s.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Convert lowercase letter to uppercase.
 *
 * @param c The character to convert.
 * @return Function returns converted character.
 */
int			ft_toupper(int c);

/**
 * @brief Convert uppercase letter to lowercase.
 *
 * @param c The character to convert.
 * @return Function returns converted character.
 */
int			ft_tolower(int c);

/**
 * @brief Function compares at most n bytes of 's1' and 's2' strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of bytes to compare.
 * @return Function returns an integer less than, equal to, or greater
 * than zero if s1 is found, respectively, to be less than, to match,
 * or be greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, t_size n);

/**
 * @brief Function compares 's1' and 's2' strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return Function returns an integer less than, equal to, or greater
 * than zero if s1 is found, respectively, to be less than, to match,
 * or be greater than s2.
 */
int			ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Function  compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 *
 * @param s1 The pointer to the first memory area.
 * @param s2 The pointer to the second memory area.
 * @param n The number of bytes to compare.
 * @return Function returns an integer less than, equal to, or greater
 * than zero if the first n bytes of s1 is found, respectively,
 * to be less than, to match, or be greater than the first n
 * bytes of s2.
 */
int			ft_memcmp(const void *s1, const void *s2, t_size n);

/**
 * @brief Function converts the initial portion of the string pointed to
 * by nptr to int.
 *
 * @param nptr The pointer to the string.
 * @return Function returns converted value.
 */
int			ft_atoi(const char *nptr);

/**
 * @brief Function locates the first occurrence of the null-terminated string
 * little in the string big, where not more than n characters are searched.
 *
 * @param big The string whare to search.
 * @param little The string to search.
 * @param n The number of characters to search.
 * @return If little is an empty string, big returned.
 * If little occurs nowhere in big, NULL returned, otherwise a
 * pointer to the first character of the occurrence of a little returned.
 */
char		*ft_strnstr(const char *big, const char *little, t_size n);

/* You must also re-code the following functions, using the function malloc */

/**
 * @brief Function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 *
 * @param nmemb
 * @param size
 * @return Function returns a pointer to the allocated memory, which is
 * suitably aligned for any built-in type. On error function returns NULL.
 * NULL may also be returned by a successful call to ft_calloc with
 * 'nmemb' or 'size' equal to zero.
 */
void		*ft_calloc(t_size nmemb, t_size size);

/**
 * @brief Function duplicates the string pointed by 's'.
 *
 * @param s The pointer to the string.
 * @return Function returns a pointer to the duplicate of the 's' string.
 * It returns NULL if insufficient memory was available, with
 * errno set to indicate the cause of the error.
 */
char		*ft_strdup(const char *s);

/* ************************************************************************** */
/* ********************** PART II -Additional Functions ********************* */
/* ************************************************************************** */

/**
 * @brief Allocates with malloc and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param s The starting from which to create substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return Function returns the substring or NULL if allocation fails.
 */
char		*ft_substr(char const *s, unsigned int start, t_size len);

/**
 * @brief Allocates with malloc and returns a new string, which
 * is the result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return Function returns the new string or NULL if allocation fails.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates with malloc and returns a copy of ’s1’ with
 * the characters specified in ’set’ removed from the beginning
 * and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param s2 The reference set of characters to trim.
 * @return Function returns the trimmed string or NULL if allocation fails.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates with malloc and returns an array of strings
 * obtained by splitting ’s’ using the character ’c’ as a delimiter.
 * The array must be ended by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return Function returns the array of new strings resulting from the
 * split or NULL if allocation fails.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Function translates an integer 'n' into a string.
 *
 * @param n The integer to convert.
 * @return The string representing the integer or NULL
 * if the allocation fails.
 */
char		*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string
 * ’s’ to create a new string with malloc resulting from
 * successive applications of ’f’.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return Function returns the string created from successive
 * applications of 'f', retruns NULL if the allocation fails.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Function applies the 'f' to each character of the string
 * passed as argument, and passing index as first argument. Each
 * character is passed by address to 'f' to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Function outputs the character 'c' to the given
 * file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptior to write.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Function outputs the string 's' to the given
 * file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptior on which to write.
 */
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Function outputs the string 's' to the given
 * file descriptor, followed by a new line.
 *
 * @param s The string to output.
 * @param fd The file descriptior on which to write.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Function outputs the integer 'n' to the given
 * file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptior on which to write.
 */
void		ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/* ******************************* Bonus Part ******************************* */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Allocates with malloc and returns a new element.
 * The variable 'content' is initialized with the value of
 * parameter 'content'. The variable 'next' is initialized to NULL.
 *
 * @param content The content to create the new element with.
 * @return Function returns the new element of the list.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Function counts the number of elements in the list.
 *
 * @param lst The beginning of the list.
 * @return Function returns the length of the list.
 */
int			ft_lstsize(t_list *lst);

/**
 * @param lst The beginning of the list.
 * @return Function returns the last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Functiom adds the element 'new' at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to
 * the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the memory
 * of the element’s content using the function ’del’ given as a
 * parameter and free the element.
 * The memory of ’next’ must not be freed.
 *
 * @param lst The element to free.
 * @param del The address of the function used to delete
 * the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given element and every
 * successor of that element, using the function ’del’ and free.
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the
 * content of the element.
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the
 * function ’f’ to the content of each element.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the
 * content of each element. Creates a new list resulting of the
 * successive applications of the function ’f’. The ’del’ function is
 * used to delete the content of an element if needed.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of an
 * element if needed.
 * @return Functon returns the new list. NULL if the allocation fails.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
