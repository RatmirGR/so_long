#include "so_long.h"

void	ft_init_sprites(t_list *cnf)
{
	ssize_t	i;
	ssize_t	count;

	cnf->spt = NULL;
	count = cnf->map->cnt_coll + cnf->map->cnt_exit;
	cnf->spt = malloc((count + 1) * sizeof(t_sprite *));
	if (cnf->spt == NULL)
		ft_print_error(cnf, ERROR_MEM, "sprite");
	i = 0;
	while (i < count)
	{
		cnf->spt[i] = NULL;
		cnf->spt[i] = malloc(sizeof(t_sprite));
		if (cnf->spt[i] == NULL)
			ft_print_error(cnf, ERROR_MEM, "sprite's value");
		cnf->spt[i]->name = '\0';
		cnf->spt[i]->pos_y = 0;
		cnf->spt[i]->pos_x = 0;
		i++;
	}
	cnf->spt[i] = NULL;
}

static void	ft_count_sprites(t_list *cnf, char c)
{
	if (c == 'P')
		cnf->map->cnt_hero += 1;
	if (c == 'F')
		cnf->map->cnt_enemy += 1;
	if (c == 'C')
		cnf->map->cnt_coll += 1;
	if (c == 'E')
		cnf->map->cnt_exit += 1;
	cnf->map->cnt_spt += 1;
}

void	ft_validate_sprites(t_list *cnf)
{
	ssize_t	i;
	ssize_t	j;

	i = 1;
	cnf->flag = 0;
	while (cnf->flag == 0 && i < cnf->map->height - 1)
	{
		j = 1;
		while (cnf->flag == 0 && j < cnf->map->width - 1)
		{
			if (ft_strchr("CEP01F", cnf->mtx[i][j]) == NULL)
				cnf->flag = 1;
			if (cnf->flag == 0 && ft_strchr("CEPF", cnf->mtx[i][j]) != NULL)
				ft_count_sprites(cnf, cnf->mtx[i][j]);
			j++;
		}
		i++;
	}
	cnf->rem_coll = cnf->map->cnt_coll;
	if (cnf->flag == 1 || cnf->map->cnt_hero > 1 || cnf->map->cnt_hero < 1)
		ft_print_error(cnf, ERROR_SPRITES, "0");
	if (cnf->map->cnt_coll < 1 || cnf->map->cnt_exit < 1)
		ft_print_error(cnf, ERROR_SPRITES, "0");
}

static void	ft_set_position(t_list *cnf, ssize_t idx, ssize_t y, ssize_t x)
{
	if (cnf->mtx[y][x] == 'C')
	{
		cnf->spt[idx]->name = 'C';
		cnf->spt[idx]->pos_y = y;
		cnf->spt[idx]->pos_x = x;
	}
	if (cnf->mtx[y][x] == 'E')
	{
		cnf->spt[idx]->name = 'E';
		cnf->spt[idx]->pos_y = y;
		cnf->spt[idx]->pos_x = x;
	}
}

void	ft_init_sprites_position(t_list *cnf)
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
			if (ft_strchr("CE", cnf->mtx[y][x]) != NULL)
			{
				ft_set_position(cnf, idx, y, x);
				idx++;
			}
			else if (cnf->mtx[y][x] == 'P')
			{
				cnf->hero->pos_y = y;
				cnf->hero->pos_x = x;
			}
			x++;
		}
		y++;
	}
}
