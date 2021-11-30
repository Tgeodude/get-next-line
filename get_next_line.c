#include "get_next_line.h"

char	*line_next_end(char *line_next, char **line)
{
	char	*pointer_n;

	pointer_n = NULL;
	if (line_next)
	{
		pointer_n = ft_strchr(line_next, '\n');
		if (pointer_n)
		{
			*pointer_n = '\0';
			*line = ft_strdup(line_next);
			line_next = ft_strdup(++pointer_n);
		}
		else
			*line = line_next;
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
	static char	*line_next[12500];
	char		*clean;

	pointer_n = line_next_end(*line_next, &line);
	while (!pointer_n)
	{
		buff[read(fd, buff, BUFFER_SIZE)] = '\0';
		pointer_n = ft_strchr(buff, '\n');
		if (pointer_n)
		{
			*pointer_n = '\0';
			*line_next = ft_strdup(++pointer_n);
		}
		clean = line;
		line = ft_strjoin(line, buff);
		free(clean);

	}
	return (line);
}

int main (void)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
