NAME					=	libftprintf.a

LIBFT					=	libft

OS						=	MACOS

SRC_FOLDER				=	./src/
SRC_SPECIFIERS_MACOS	=	specifiers_macos/print_int.c			\
							specifiers_macos/print_uint.c			\
							specifiers_macos/print_hexa.c			\
							specifiers_macos/print_char.c 			\
							specifiers_macos/print_width.c			\
							specifiers_macos/print_string.c 		\
							specifiers_macos/print_pointer.c		\
							
SRC_SPECIFIERS_LINUX	=	specifiers_linux/print_int.c			\
							specifiers_linux/print_uint.c			\
							specifiers_linux/print_hexa.c			\
							specifiers_linux/print_char.c 			\
							specifiers_linux/print_width.c			\
							specifiers_linux/print_string.c 		\
							specifiers_linux/print_pointer.c		\

SRC_FILES				=	ft_printf.c								\
							init_flags.c							\
							parse_zero.c							\
							parse_wl.c								\
							select_specifier.c

ifeq ($(OS), MACOS)
OBJS					=	$(addprefix $(SRC_FOLDER), $(SRC_FILES))			\
							$(addprefix $(SRC_FOLDER), $(SRC_SPECIFIERS_MACOS))
else
OBJS					=	$(addprefix $(SRC_FOLDER), $(SRC_FILES))			\
							$(addprefix $(SRC_FOLDER), $(SRC_SPECIFIERS_LINUX))
endif
OBJS					:=	$(OBJS:.c=.o)

INCLUDE					=	./includes/

ECHO					=	echo
CC						=	gcc
RM						=	rm -rf

CFLAGS					=	-Wall -Wextra -Werror

C_RESET					=	\033[0m
C_PENDING				=	\033[0;36m
C_SUCCESS				=	\033[0;32m

ES_ERASE				=	"\033[A\033[K\033[A"
ERASE					=	$(ECHO) $(ES_ERASE)

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
