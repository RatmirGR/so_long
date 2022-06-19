#include "so_long.h"

static char	*ft_init(char *p, int size, int n)
{
	int	i;
	int	num;

	i = 0;
	if (size < 0)
	{
		p[i] = '-';
		++i;
	}
	while (size != 0)
	{
		num = n / size;
		n %= size;
		size /= 10;
		p[i] = (num + '0');
		++i;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		num;
	int		size;
	int		i;
	char	*p;

	size = 1;
	i = 0;
	if (n < 0)
	{
		size = -size;
		++i;
	}
	num = n;
	while ((num / 10) != 0)
	{
		num /= 10;
		size *= 10;
		++i;
	}
	p = NULL;
	p = (char *)malloc((i + 2) * sizeof(char));
	if (p != NULL)
		p = ft_init(p, size, n);
	return (p);
}
