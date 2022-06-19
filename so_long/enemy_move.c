#include "so_long.h"

void	ft_move_left_enemy(t_list *cnf, ssize_t i)
{
	int		width;
	int		height;
	void	*path;
	ssize_t	w;
	ssize_t	h;

	cnf->enemy[i]->c = cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x - 1];
	if (cnf->enemy[i]->c == 'P')
		ft_print_msg(cnf, "you were caught (:\n");
	ft_fill_floor(cnf, cnf->enemy[i]->pos_y, cnf->enemy[i]->pos_x);
	cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x] = '0';
	cnf->enemy[i]->pos_x -= 1;
	cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x] = 'F';
	path = mlx_xpm_file_to_image(cnf->mlx, IMG_3L, &width, &height);
	if (path == NULL)
		ft_print_error(cnf, ERROR_MEM, "error path mlx");
	w = cnf->enemy[i]->pos_x;
	h = cnf->enemy[i]->pos_y;
	mlx_put_image_to_window(cnf->mlx, cnf->wds, path, w * W_IMG, h * H_IMG);
	mlx_destroy_image(cnf->mlx, path);
}

void	ft_move_right_enemy(t_list *cnf, ssize_t i)
{
	int		width;
	int		height;
	void	*path;
	ssize_t	w;
	ssize_t	h;

	cnf->enemy[i]->c = cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x + 1];
	if (cnf->enemy[i]->c == 'P')
		ft_print_msg(cnf, "you were caught (:\n");
	ft_fill_floor(cnf, cnf->enemy[i]->pos_y, cnf->enemy[i]->pos_x);
	cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x] = '0';
	cnf->enemy[i]->pos_x += 1;
	cnf->mtx[cnf->enemy[i]->pos_y][cnf->enemy[i]->pos_x] = 'F';
	path = mlx_xpm_file_to_image(cnf->mlx, IMG_3R, &width, &height);
	if (path == NULL)
		ft_print_error(cnf, ERROR_MEM, "error path mlx");
	w = cnf->enemy[i]->pos_x;
	h = cnf->enemy[i]->pos_y;
	mlx_put_image_to_window(cnf->mlx, cnf->wds, path, w * W_IMG, h * H_IMG);
	mlx_destroy_image(cnf->mlx, path);
}

void	ft_change_left_or_right_site(t_list *cnf, ssize_t idx)
{
	if ((cnf->enemy[idx]->r == '0' || cnf->enemy[idx]->r == 'P')
		|| (cnf->enemy[idx]->l == '0' || cnf->enemy[idx]->l == 'P'))
	{
		if ((cnf->enemy[idx]->r == '0' || cnf->enemy[idx]->r == 'P')
			&& cnf->enemy[idx]->flag1 == 1)
		{
			cnf->enemy[idx]->flag2 = 2;
			ft_move_right_enemy(cnf, idx);
		}
		else
			cnf->enemy[idx]->flag2 = 1;
		if ((cnf->enemy[idx]->l == '0' || cnf->enemy[idx]->l == 'P')
			&& cnf->enemy[idx]->flag2 == 1)
		{
			cnf->enemy[idx]->flag1 = 2;
			ft_move_left_enemy(cnf, idx);
		}
		else
			cnf->enemy[idx]->flag1 = 1;
	}
}

void	ft_change_up_or_down_site(t_list *cnf, ssize_t idx)
{
	int		width;
	int		height;
	void	*path;
	ssize_t	w;
	ssize_t	h;

	if (cnf->enemy[idx]->u == '0' || cnf->enemy[idx]->u == 'P'
		|| cnf->enemy[idx]->d == '0' || cnf->enemy[idx]->d == 'P')
	{
		if (cnf->enemy[idx]->l != '0' && cnf->enemy[idx]->l != 'P'
			&& cnf->enemy[idx]->r != '0' && cnf->enemy[idx]->r != 'P')
		{
			path = mlx_xpm_file_to_image(cnf->mlx, IMG_3R, &width, &height);
			if (path == NULL)
				ft_print_error(cnf, ERROR_MEM, "error path mlx");
			w = cnf->enemy[idx]->pos_x;
			h = cnf->enemy[idx]->pos_y;
			mlx_put_image_to_window(cnf->mlx, cnf->wds, path, w * W, h * H);
			mlx_destroy_image(cnf->mlx, path);
		}
	}
}

int	ft_move_enemy(t_list *cnf)
{
	ssize_t	idx;

	cnf->step_rnd += 1;
	if (cnf->step_rnd % 100 == 0 && cnf->step_rnd < 300)
	{
		idx = 0;
		while (idx < cnf->map->cnt_enemy)
		{
			ft_init_enemy_position(cnf);
			ft_get_side(cnf, idx);
			ft_change_left_or_right_site(cnf, idx);
			ft_change_up_or_down_site(cnf, idx);
			idx++;
		}
	}
	if (cnf->step_rnd % 15 == 0)
		ft_init_window(cnf, 2);
	else if (cnf->step_rnd % 250 == 0)
		ft_init_window(cnf, 1);
	if (cnf->step_rnd == 300)
		cnf->step_rnd = 0;
	return (0);
}
