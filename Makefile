############### NAME #####################

NAME	= so_long

############# SOURCES ###################

SRCS	=	src/main.c \
		src/mouvement.c \
		src/exit.c \
		src/verif.c \
		src/lecture_map.c \
		src/position.c \
		src/init_game.c \
		src/destroy.c

############## VARIABLES ################

LIB		=	ft_printf/printf.a ft_libft/libft.a
MLXFLAGS 	=	-L ./minilibx/libmlx.a ./minilibx/libmlx_Linux.a -Ilmlx -lXext -lX11
OBJS		=	$(SRCS:.c=.o)
RM		=	@rm -f
CC		=	@cc
CFLAGS		=	-Wall -Wextra -Werror -g3

############## REGLES ###################

all	:	$(NAME)

$(MLX)	:
		@make -C minilibx

$(NAME)	:	$(MLX)	$(OBJS)
				@echo "\033[0;33mCompilation...\033[0m"
				@make --no-print-directory -C ft_printf/
				$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
				@echo "\033[0;32mCompilation : OK.\033[0m"
					
clean	:	
		@echo "\033[0;33mclean...\033[0m"
		$(RM) $(OBJS)
		@echo "\033[0;32mclean : OK.\033[0m"

fclean	:	clean
			@$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
