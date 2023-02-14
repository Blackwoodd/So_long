NAME	= so_long

SRCS	= src/main.c src/mouvement.c src/exit.c src/verif.c src/lecture_map.c src/position.c src/init_game.c src/destroy.c
LIB		= ft_printf/printf.a ft_libft/libft.a
MLXFLAGS = -L ./minilibx -lmlx -Ilmlx -lXext -lX11
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
CC		= @cc
CFLAGS	= -Wall -Wextra -Werror -g3

all	: 	$(NAME)

$(NAME)	:	$(OBJS)
			@make --no-print-directory -C ft_printf/
			@$(MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)

$(MLX)	:	make -C minilibx
					
clean	:
				@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean	all

.PHONY	:	all clean fclean re