NAME		= printf.a

SRCS 		= ft_printfs.c \
		ft_putnbr_ui.c \
		ft_printfi.c ft_printfu.c \
		ft_printfc.c ft_printfp.c \
		ft_printfx.c printf.c \
		ft_printfd.c ft_printfupx.c \
		ft_putnbr_int.c \

RM		= rm -rf

OBJS		= ${SRCS:.c=.o}

CC		= gcc
FLAGS		= -Wall -Wextra -Werror

all	:	${NAME}
	
$(NAME)	:	${OBJS} 
			ar rcs $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re	: 	fclean $(NAME)
	
.PHONY	: 	all clean fclean
