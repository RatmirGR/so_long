#include "so_long.h"

static void	ft_move_up(t_list *cnf)
{
	char	ch;

	ch = cnf->mtx[cnf->hero->pos_y - 1][cnf->hero->pos_x];
	if (ch == '0' || ch == 'F' || ch == 'C')
	{
		if (ch == 'C')
			ft_take_coll(cnf);
		else if (ch == 'F')
			ft_print_msg(cnf, "you were caught (:\n");
		ft_fill_floor(cnf, cnf->hero->pos_y, cnf->hero->pos_x);
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = '0';
		cnf->hero->pos_y -= 1;
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = 'P';
		cnf->hero->side = 'r';
		cnf->count_steps += 1;
		ft_print_count(cnf->count_steps);
		ft_init_window(cnf, 2);
	}
	if (ch == 'V')
		ft_print_msg(cnf, "you won =) Happy new year\n");
}

static void	ft_move_left(t_list *cnf)
{
	char	ch;

	ch = cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x - 1];
	if (ch == '0' || ch == 'F' || ch == 'C')
	{
		if (ch == 'C')
			ft_take_coll(cnf);
		else if (ch == 'F')
			ft_print_msg(cnf, "you were caught (:\n");
		ft_fill_floor(cnf, cnf->hero->pos_y, cnf->hero->pos_x);
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = '0';
		cnf->hero->pos_x -= 1;
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = 'P';
		cnf->hero->side = 'l';
		cnf->count_steps += 1;
		ft_print_count(cnf->count_steps);
		ft_init_window(cnf, 2);
	}
	if (ch == 'V')
		ft_print_msg(cnf, "you won =) Happy new year\n");
}

static void	ft_move_right(t_list *cnf)
{
	char	ch;

	ch = cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x + 1];
	if (ch == '0' || ch == 'F' || ch == 'C')
	{
		if (ch == 'C')
			ft_take_coll(cnf);
		else if (ch == 'F')
			ft_print_msg(cnf, "you were caught (:\n");
		ft_fill_floor(cnf, cnf->hero->pos_y, cnf->hero->pos_x);
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = '0';
		cnf->hero->pos_x += 1;
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = 'P';
		cnf->hero->side = 'r';
		cnf->count_steps += 1;
		ft_print_count(cnf->count_steps);
		ft_init_window(cnf, 2);
	}
	if (ch == 'V')
		ft_print_msg(cnf, "you won =) Happy new year\n");
}

static void	ft_move_down(t_list *cnf)
{
	char	ch;

	ch = cnf->mtx[cnf->hero->pos_y + 1][cnf->hero->pos_x];
	if (ch == '0' || ch == 'F' || ch == 'C')
	{
		if (ch == 'C')
			ft_take_coll(cnf);
		else if (ch == 'F')
			ft_print_msg(cnf, "you were caught (:\n");
		ft_fill_floor(cnf, cnf->hero->pos_y, cnf->hero->pos_x);
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = '0';
		cnf->hero->pos_y += 1;
		cnf->mtx[cnf->hero->pos_y][cnf->hero->pos_x] = 'P';
		cnf->hero->side = 'l';
		cnf->count_steps += 1;
		ft_print_count(cnf->count_steps);
		ft_init_window(cnf, 2);
	}
	if (ch == 'V')
		ft_print_msg(cnf, "you won =) Happy new year\n");
}

int	ft_press_key(int key, t_list *cnf)
{
	if (key == ESC_KEY)
		ft_close(cnf);
	if (key == W_KEY || key == UP_KEY)
		ft_move_up(cnf);
	if (key == A_KEY || key == LEFT_KEY)
		ft_move_left(cnf);
	if (key == D_KEY || key == RIGHT_KEY)
		ft_move_right(cnf);
	if (key == S_KEY || key == DOWN_KEY)
		ft_move_down(cnf);
	return (0);
}
