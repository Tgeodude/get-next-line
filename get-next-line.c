#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (i++, s1[i])
		s3[i] = s1[i];
	while (j++, s2[j])
	{
		s3[i] = s2[j];
		i++;
	}
	s3[i] = 0;
	return (s3);
}

char	*ft_strchr(const char *string, int symbol)
{
	unsigned char	tmp;

	tmp = symbol;
	while (*string)
	{
		if (*string == tmp)
			return ((char *)string);
		string++;
	}
	if (symbol == '\0')
		return ((char *)(string + ft_strlen(string)));
	return (0);
}

char	*get_next_line(int fd)
{
	char	buffer[11 + 1];
	char	*line;
	int	bwr;
	char	*line_for;
	int	flag;

	flag = 1;
	line = "\0";
	while (flag && (bwr = read(fd, buffer, 11)))
	{
		if (line_for = ft_strchr(buffer,'\n'))
		{
			*line_for = 0;
			flag = 0;
		}
		buffer[bwr] = 0;
		line = ft_strjoin(line, buffer);
	}
	line = ft_strjoin(line, line_for);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt",O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return (0);
}
