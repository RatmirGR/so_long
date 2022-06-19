#include "so_long.h"

void	ft_fill_floor(t_list *cnf, ssize_t h, ssize_t w)
{
	void	*path;
	int		width;
	int		height;

	path = mlx_xpm_file_to_image(cnf->mlx, IMG_4, &width, &height);
	if (path == NULL)
		ft_print_error(cnf, ERROR_MEM, "error path mlx");
	mlx_put_image_to_window(cnf->mlx, cnf->wds, path, w * W_IMG, h * H_IMG);
	mlx_destroy_image(cnf->mlx, path);
}

static void	*ft_init_border(t_list *cnf, ssize_t h, ssize_t w, ssize_t flag)
{
	int		width;
	int		height;
	void	*path;

	if (h == 0 && (w >= 1 && w <= 2))
		path = mlx_xpm_file_to_image(cnf->mlx, IMG_6C, &width, &height);
	else if (w % 2 == 0 && flag == 2 && (h == 0 || h == cnf->map->height - 1))
		path = mlx_xpm_file_to_image(cnf->mlx, IMG_6A, &width, &height);
	else
		path = mlx_xpm_file_to_image(cnf->mlx, IMG_6B, &width, &height);
	return (path);
}

static void	*ft_view_hero(t_list *cnf)
{
	int		width;
	int		height;
	void	*path;

	path = NULL;
	if (cnf->hero->side == 'r')
		path = mlx_xpm_file_to_image(cnf->mlx, IMG_1R, &width, &height);
	else
		path = mlx_xpm_file_to_image(cnf->mlx, IMG_1L, &width, &height);
	return (path);
}

static void	ft_fill_map(t_list *cnf, ssize_t h, ssize_t w, ssize_t flag)
{
	void	*path;
	int		width;
	int		height;

	if (ft_strchr("PCE1V", cnf->mtx[h][w]) != NULL)
	{
		if (cnf->mtx[h][w] == 'P')
			path = ft_view_hero(cnf);
		if (cnf->mtx[h][w] == 'C')
			path = mlx_xpm_file_to_image(cnf->mlx, IMG_5, &width, &height);
		if (cnf->mtx[h][w] == 'E')
			path = mlx_xpm_file_to_image(cnf->mlx, IMG_2, &width, &height);
		if (cnf->mtx[h][w] == '1')
			path = ft_init_border(cnf, h, w, flag);
		if (cnf->mtx[h][w] == 'V')
			path = mlx_xpm_file_to_image(cnf->mlx, IMG_1, &width, &height);
		if (path == NULL)
			ft_print_error(cnf, ERROR_MEM, "error path mlx");
		mlx_put_image_to_window(cnf->mlx, cnf->wds, path, w * W_IMG, h * H_IMG);
		mlx_destroy_image(cnf->mlx, path);
	}
}

void	ft_init_window(t_list *cnf, ssize_t flag)
{
	ssize_t	w;
	ssize_t	h;
	char	*str;
	char	*count;

	h = 0;
	while (h < cnf->map->height)
	{
		w = 0;
		while (w < cnf->map->width)
		{
			if (flag == 0)
				ft_fill_floor(cnf, h, w);
			else
				ft_fill_map(cnf, h, w, flag);
			w++;
		}
		h++;
	}
	count = ft_itoa(cnf->count_steps);
	str = "COUNT STEPS:";
	mlx_string_put(cnf->mlx, cnf->wds, 70, 24, 0xFFFFFFFF, str);
	mlx_string_put(cnf->mlx, cnf->wds, 165, 24, 0xFFFFFF00, count);
	free(count);
}
