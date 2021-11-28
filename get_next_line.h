#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SZ
# define BUFFER_SZ 1
# endif

char		*get_next_line(int fd);
char		*ft_strdup(const char *str);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlen(const char *string);
char		*ft_strjoin(char const *s1,char const *s2);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(char *str, int c);

#endif
