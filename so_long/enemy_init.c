#include "so_long.h"

void	ft_init_enemy(t_list *cnf)
{
	ssize_t	i;

	cnf->enemy = NULL;
	cnf->enemy = malloc((cnf->map->cnt_enemy + 1) * sizeof(t_enemy *));
	if (cnf->enemy == NULL)
		ft_print_error(cnf, ERROR_MEM, "enemy");
	i = 0;
	while (i < cnf->map->cnt_enemy)
	{
		cnf->enemy[i] = NULL;
		cnf->enemy[i] = malloc(sizeof(t_enemy));
		if (cnf->enemy[i] == NULL)
			ft_print_error(cnf, ERROR_MEM, "enemy's value");
		cnf->enemy[i]->pos_y = 0;
		cnf->enemy[i]->pos_x = 0;
		cnf->enemy[i]->flag1 = 1;
		cnf->enemy[i]->flag2 = 1;
		i++;
	}
	cnf->enemy[i] = NULL;
}

void	ft_init_enemy_position(t_list *cnf)
{
	ssize_t	y;
	ssize_t	x;
	ssize_t	idx;

	y = 1;
	idx = 0;
	while (y < cnf->map->height - 1)
	{
		x = 1;
		while (x < cnf->map->width - 1)
		{
			if (cnf->mtx[y][x] == 'F')
			{
				cnf->enemy[idx]->pos_y = y;
				cnf->enemy[idx]->pos_x = x;
				idx++;
			}
			x++;
		}
		y++;
	}
}

void	ft_get_side(t_list *cnf, ssize_t idx)
{
	char	l;
	char	r;
	char	u;
	char	d;

	l = cnf->mtx[cnf->enemy[idx]->pos_y][cnf->enemy[idx]->pos_x - 1];
	r = cnf->mtx[cnf->enemy[idx]->pos_y][cnf->enemy[idx]->pos_x + 1];
	u = cnf->mtx[cnf->enemy[idx]->pos_y - 1][cnf->enemy[idx]->pos_x];
	d = cnf->mtx[cnf->enemy[idx]->pos_y + 1][cnf->enemy[idx]->pos_x];
	cnf->enemy[idx]->l = l;
	cnf->enemy[idx]->r = r;
	cnf->enemy[idx]->u = u;
	cnf->enemy[idx]->d = d;
}
