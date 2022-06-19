#include "so_long.h"

void	ft_print_count(ssize_t count)
{
	char	*str;

	str = ft_itoa(count);
	write(1, "number of steps :", 17);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

int	ft_close(t_list *cnf)
{
	mlx_destroy_window(cnf->mlx, cnf->wds);
	ft_free(cnf);
	exit(0);
}

void	ft_print_msg(t_list *cnf, char *msg)
{
	write(1, msg, ft_strlen(msg));
	ft_close(cnf);
}

void	ft_take_coll(t_list *cnf)
{
	ssize_t	i;

	cnf->rem_coll--;
	if (cnf->rem_coll == 0)
	{
		write(1, "you collected all the gifts :)\n", 31);
		i = 0;
		while (i < cnf->map->cnt_exit + cnf->map->cnt_coll)
		{
			if (cnf->spt[i]->name == 'E')
				cnf->mtx[cnf->spt[i]->pos_y][cnf->spt[i]->pos_x] = 'V';
			i++;
		}
	}
	else
		write(1, "you took a gift\n", 16);
}
