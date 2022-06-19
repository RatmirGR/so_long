#include "so_long.h"

void	ft_free(t_list *cnf)
{
	ssize_t	i;

	if (cnf != NULL)
	{
		if (cnf->map != NULL)
			free(cnf->map);
		if (cnf->hero != NULL)
			free(cnf->hero);
		i = 0;
		while (cnf->spt != NULL && i < cnf->map->cnt_exit + cnf->map->cnt_coll)
			free(cnf->spt[i++]);
		if (cnf->spt != NULL)
			free(cnf->spt);
		i = 0;
		while (cnf->enemy != NULL && i < cnf->map->cnt_enemy)
			free(cnf->enemy[i++]);
		if (cnf->enemy != NULL)
			free(cnf->enemy);
		i = 0;
		while (i < cnf->mtx_h)
			free(cnf->mtx[i++]);
		if (cnf->mtx != NULL)
			free(cnf->mtx);
		free(cnf);
	}
}

void	ft_print_error(t_list *cnf, char *desc, char *name)
{
	if (ft_strchr(name, '0') != NULL)
		write(2, "Error\n", 6);
	else
		write(2, "So_long: ", 9);
	write(2, desc, ft_strlen(desc));
	write(2, ": ", 2);
	write(2, name, ft_strlen(name));
	write(2, "\n", 1);
	ft_free(cnf);
	if (ft_strchr(name, '0') != NULL)
		exit(0);
	else
		exit(1);
}

int	ft_line_len(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (to_find[len] != '\0')
		++len;
	if (len == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (j < len && str[i] == to_find[j])
		{
			++i;
			++j;
		}
		if (j == len)
			return (&str[i - len]);
		i = i - (j - 1);
		j = 0;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		++i;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}
