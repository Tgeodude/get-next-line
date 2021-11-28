#include "get_next_line.h"

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

