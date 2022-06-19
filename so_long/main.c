#include "so_long.h"

void	ft_init_mlx(t_list *cnf)
{
	ssize_t	w;
	ssize_t	h;

	cnf->mlx = mlx_init();
	w = cnf->map->width;
	h = cnf->map->height;
	cnf->wds = mlx_new_window(cnf->mlx, w * W_IMG, h * H_IMG, "So Long");
}

void	ft_game(t_list *cnf)
{
	mlx_hook(cnf->wds, 2, 0, ft_press_key, cnf);
	mlx_hook(cnf->wds, 17, 1L << 0, ft_close, cnf);
	if (cnf->map->cnt_enemy > 0)
		mlx_loop_hook(cnf->mlx, ft_move_enemy, cnf);
	mlx_loop(cnf->mlx);
}

int	main(int argc, char *argv[])
{
	t_list	*cnf;

	ft_validate_args(argc, argv);
	cnf = ft_init_config();
	ft_open_file(cnf, argv[1]);
	ft_validate_map(cnf);
	ft_validate_sprites(cnf);
	ft_init_sprites(cnf);
	ft_init_sprites_position(cnf);
	ft_init_mlx(cnf);
	ft_init_enemy(cnf);
	ft_init_window(cnf, 0);
	ft_init_window(cnf, 1);
	ft_game(cnf);
	return (0);
}
