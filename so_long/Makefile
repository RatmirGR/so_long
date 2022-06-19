NAME = so_long

HEADER = so_long.h

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

SRCS = main.c init_config.c sprites.c map.c enemy_move.c get_next_line.c\
		enemy_init.c print_msg.c so_long_utils.c ft_split.c move_hero.c\
		ft_itoa.c validate.c

MLX_SRCS = ./mlx/libmlx.a

OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(MLX_SRCS) $(NAME)

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX_SRCS) :
	make -C ./mlx

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make clean -C mlx/

re : fclean all

.PHONY: all clean fclean re bonus