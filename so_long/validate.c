#include "so_long.h"

void	ft_validate_args(int ac, char *av[])
{
	if (ac > 2)
		ft_print_error(NULL, MANY_ARGS, "1");
	else if (ac < 2)
		ft_print_error(NULL, FEW_ARGS, "1");
	else if (ac == 2 && ft_strstr(av[1], ".ber") == NULL)
		ft_print_error(NULL, ERROR_ARG, "1");
}

static ssize_t	ft_get_height_mtx(char *tmp)
{
	ssize_t	i;
	ssize_t	count_line;

	count_line = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			count_line++;
		i++;
	}
	if (count_line > 0 && tmp[i] == '\0')
		count_line++;
	return (count_line);
}

void	ft_open_file(t_list *cnf, char *file)
{
	ssize_t	fd;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_print_error(NULL, ERROR_OPEN, file);
	tmp = get_next_line(fd);
	if (close(fd) == -1)
		ft_print_error(NULL, ERROR_CLOSE, "1");
	if (tmp == NULL)
		ft_print_error(cnf, ERROR_MEM, "open - tmp");
	cnf->mtx_h = ft_get_height_mtx(tmp);
	cnf->mtx = ft_split(tmp, '\n');
	free(tmp);
	if (cnf->mtx == NULL)
		ft_print_error(cnf, ERROR_MEM, "matrix");
}

void	ft_validate_map(t_list *cnf)
{
	ssize_t	i;

	cnf->map->width = ft_strlen(cnf->mtx[0]);
	cnf->map->height = ft_line_len(cnf->mtx);
	i = -1;
	if (cnf->map->height != cnf->mtx_h)
		cnf->flag = 1;
	while (cnf->flag == 0 && (++i) < cnf->map->height - 1)
		if (ft_strlen(cnf->mtx[i]) != ft_strlen(cnf->mtx[i + 1]))
			cnf->flag = 1;
	i = -1;
	while (cnf->flag == 0 && (++i) < cnf->map->width)
		if (cnf->mtx[0][i] != '1')
			cnf->flag = 1;
	i = 0;
	while (cnf->flag == 0 && (++i) < cnf->map->height - 1)
		if (cnf->mtx[i][0] != '1' || cnf->mtx[i][cnf->map->width - 1] != '1')
			cnf->flag = 1;
	i = -1;
	while (cnf->flag == 0 && (++i) < cnf->map->width)
		if (cnf->mtx[cnf->map->height - 1][i] != '1')
			cnf->flag = 1;
	if (cnf->flag == 1)
		ft_print_error(cnf, INVALID_MAP, "0");
}
