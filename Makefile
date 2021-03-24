NAME		=	libftprintf.a

LIBFT		=	libft

SRC_FOLDER	=	./src/
SRC_FILES	=	ft_printf.c						\
				init_flags.c					\
				parse_zero.c					\
				parse_wl.c						\
				select_specifier.c				\
				specifier/print_int.c			\
				specifier/print_uint.c			\
				specifier/print_hexa.c			\
				specifier/print_char.c 			\
				specifier/print_width.c			\
				specifier/print_string.c 		\
				specifier/print_pointer.c		\


OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES))
OBJS		:=	$(OBJS:.c=.o)

INCLUDE		=	./includes/

ECHO		=	echo
CC			=	gcc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

C_RESET		=	\033[0m
C_PENDING	=	\033[0;36m
C_SUCCESS	=	\033[0;32m

ES_ERASE	=	"\033[A\033[K\033[A"
ERASE		=	$(ECHO) $(ES_ERASE)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp ./libft/libft.a ./$(NAME)
		ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
