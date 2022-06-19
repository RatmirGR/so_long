#include "so_long.h"

void	ft_init_map_value(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->cnt_hero = 0;
	map->cnt_enemy = 0;
	map->cnt_coll = 0;
	map->cnt_exit = 0;
	map->cnt_spt = 0;
}

void	ft_init_hero_value(t_hero *hero)
{
	hero->side = '\0';
	hero->pos_y = 0;
	hero->pos_x = 0;
}

t_list	*ft_init_config(void)
{
	t_list	*p;

	p = NULL;
	p = malloc(sizeof(t_list));
	if (p == NULL)
		ft_print_error(NULL, ERROR_MEM, "root");
	p->map = NULL;
	p->map = malloc(sizeof(t_map));
	if (p->map == NULL)
		ft_print_error(p, ERROR_MEM, "map");
	ft_init_map_value(p->map);
	p->hero = NULL;
	p->hero = malloc(sizeof(t_hero));
	if (p->hero == NULL)
		ft_print_error(p, ERROR_MEM, "hero");
	ft_init_hero_value(p->hero);
	p->mtx = NULL;
	p->mtx_h = 0;
	p->mlx = NULL;
	p->wds = NULL;
	p->count_steps = 0;
	p->rem_coll = 0;
	p->flag = 0;
	p->step_rnd = 0;
	return (p);
}
