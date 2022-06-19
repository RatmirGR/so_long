#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FEW_ARGS "Few arguments specified"
# define MANY_ARGS "Many arguments specified"
# define ERROR_ARG "Wrong file extension. You must specify the extension .ber"
# define ERROR_OPEN "Failed to open the file"
# define ERROR_CLOSE "Failed to close the file"
# define ERROR_MEM "Memory allocation error"
# define INVALID_MAP "Invalid map"
# define ERROR_SPRITES "Wrong number of sprites"

# define W_IMG 64
# define H_IMG 64
# define W W_IMG
# define H H_IMG

# define IMG_1 "./img/exit2.xpm"
# define IMG_2 "./img/exit1.xpm"
# define IMG_1R "./img/santa1.xpm"
# define IMG_1L "./img/santa2.xpm"
# define IMG_3R "./img/enemy1.xpm"
# define IMG_3L "./img/enemy2.xpm"
# define IMG_4 "./img/floor.xpm"
# define IMG_5 "./img/surprise.xpm"
# define IMG_6A "./img/tree1.xpm"
# define IMG_6B "./img/tree2.xpm"
# define IMG_6C "./img/board.xpm"

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define UP_KEY 126
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdio.h>

typedef struct s_hero
{
	ssize_t	pos_y;
	ssize_t	pos_x;
	char	side;
}			t_hero;

typedef struct s_enemy
{
	ssize_t	pos_y;
	ssize_t	pos_x;
	char	l;
	char	r;
	char	u;
	char	d;
	char	c;
	ssize_t	flag1;
	ssize_t	flag2;
}			t_enemy;

typedef struct s_sprite
{
	char	name;
	ssize_t	pos_y;
	ssize_t	pos_x;
}			t_sprite;

typedef struct s_map
{
	ssize_t	width;
	ssize_t	height;
	ssize_t	cnt_hero;
	ssize_t	cnt_enemy;
	ssize_t	cnt_coll;
	ssize_t	cnt_exit;
	ssize_t	cnt_spt;
}			t_map;

typedef struct s_list
{
	char		**mtx;
	ssize_t		mtx_h;
	t_map		*map;
	t_hero		*hero;
	t_sprite	**spt;
	t_enemy		**enemy;
	ssize_t		flag;
	void		*mlx;
	void		*wds;
	ssize_t		count_steps;
	ssize_t		rem_coll;
	ssize_t		step_rnd;
}				t_list;

void	ft_free(t_list *cnf);
void	ft_print_error(t_list *cnf, char *desc, char *name);
int		ft_line_len(char **line);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
void	ft_validate_args(int ac, char *av[]);
t_list	*ft_init_config(void);
void	ft_open_file(t_list *cnf, char *file);
void	ft_validate_map(t_list *cnf);
void	ft_init_sprites(t_list *cnf);
void	ft_validate_sprites(t_list *cnf);
void	ft_init_sprites_position(t_list *cnf);
void	ft_print_count(ssize_t count);
int		ft_close(t_list *cnf);
void	ft_print_msg(t_list *cnf, char *msg);
void	ft_take_coll(t_list *cnf);
void	ft_fill_floor(t_list *cnf, ssize_t h, ssize_t w);
void	ft_init_window(t_list *cnf, ssize_t flag);
void	ft_init_enemy(t_list *cnf);
void	ft_init_enemy_position(t_list *cnf);
int		ft_move_enemy(t_list *cnf);
void	ft_move_left_enemy(t_list *cnf, ssize_t idx);
void	ft_move_right_enemy(t_list *cnf, ssize_t idx);
void	ft_get_side(t_list *cnf, ssize_t idx);
int		ft_press_key(int key, t_list *cnf);

#endif
