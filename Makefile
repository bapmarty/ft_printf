NAME		=	libftprintf.a

LIBFT		=	libft

SRC_FOLDER	=	./src/
SRC_FILES	=	ft_printf.c					\
				init_params.c				\
				specifier/print_percent.c 	\
				specifier/print_params.c	\
				specifier/print_cs.c 		\


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

norm:
	#@~/.norminette/norminette.rb ./libft/*.c
	@norminette -d src
	@norminette -d include

test:
	@clear
	@$(ECHO) "Compiling...\t[$(C_PENDING) ⌛︎ $(C_RESET)]"
	@make
	@gcc main.c -L. -lftprintf -I $(INCLUDE)
	@$(ECHO) "Compiling...\t[$(C_SUCCESS) ✅ $(C_RESET)]"
rmtest: clean
	@$(RM) a.out
.PHONY: all clean fclean re