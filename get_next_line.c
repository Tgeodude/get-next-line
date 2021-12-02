#include "get_next_line.h"

char	*line_next_end(char **line_next, char **line)
{
	char	*pointer_n;
	char	*clean;

	pointer_n = NULL;
	if (*line_next)
	{
		pointer_n = ft_strchr(*line_next, '\n');
		if (pointer_n)
		{
			clean = *line_next;
			*line = ft_strdup(*line_next);
			*line_next = ft_strdup(++pointer_n);
			free(clean);
			*pointer_n = '\0';
		}
		else
		{
			*line = *line_next;
			*line_next = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (pointer_n);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	char		*pointer_n;
	static char	*line_next;
	char		*clean;
	int		bf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	bf = 1;
	pointer_n = line_next_end(&line_next, &line);
	while (!pointer_n && bf && !line_next)
	{	
		bf = read(fd, buff, BUFFER_SIZE);
		if (bf <= 0  && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buff[bf] = '\0';
		pointer_n = ft_strchr(buff, '\n');
		if (pointer_n)
		{
			line_next = ft_strdup(++pointer_n);
			*pointer_n = '\0';
		}
		clean = line;
		line = ft_strjoin(line, buff);
		free(clean);

	}
	return (line);
}

/*int main (void)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/
