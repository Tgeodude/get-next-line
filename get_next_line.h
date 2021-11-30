#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


void		*ft_memcpy(void *dest, const void *src, size_t len);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1,char const *s2);
char		*ft_strchr(const char *string, int symbol);

#endif
