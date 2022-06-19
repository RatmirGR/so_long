#include "so_long.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	size_t			len;
	unsigned char	*s;

	len = nmemb * size;
	p = NULL;
	p = malloc(len);
	if (p != NULL)
	{
		s = (unsigned char *)p;
		while (len--)
			*s++ = (unsigned char)0;
	}
	return (p);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	p = NULL;
	i = (ft_strlen(s1) + ft_strlen(s2));
	p = (char *)malloc((i + 1) * sizeof(char));
	if (p != NULL)
	{
		i = -1;
		while (s1[++i])
			p[i] = s1[i];
		j = -1;
		while (s2[++j])
		{
			p[i] = s2[j];
			++i;
		}
		p[i] = '\0';
	}
	free((void *)s1);
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*ftext;
	ssize_t		count;

	buf = NULL;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf != NULL)
	{
		if (ftext == NULL)
			ftext = ft_calloc(1, sizeof(char));
		count = 1;
		while (count > 0)
		{
			count = read(fd, buf, BUFFER_SIZE);
			if (count < 0)
				break ;
			buf[count] = '\0';
			ftext = ft_strjoin(ftext, buf);
		}
		free(buf);
		buf = NULL;
		return (ftext);
	}
	return (0);
}
