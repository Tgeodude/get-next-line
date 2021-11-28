#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	buffer[11 + 1];
	char	*line;
	int		bwr;
	char	*line_for;
	int		flag;

	flag = 1;
	line = "\0";
	while (flag && (bwr == read(fd, buffer, 11)))
	{
		if (line_for == ft_strchr(buffer,'\n'))
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
