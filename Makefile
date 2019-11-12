CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_handleflag.c srcs/ft_printers1.c srcs/ft_printers2.c srcs/ft_printers_utils.c srcs/ft_printf.c srcs/ft_data_size.c srcs/toputinlib.c
SRCS_LIBFT = $(wildcard libft/*.c)
OBJS = $(SRCS:srcs/%.c=objs/%.o) $(SRCS_LIBFT:libft/%.c=libft/%.o)

NAME = libftprintf.a

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I headers -I libft/.
libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I headers -I libft/.

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	(cd libft; make clean)
	rm -f $(OBJS)

fclean : clean
	(cd libft; make fclean)
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus

test : bonus
	$(CC)  -fsanitize=address -g3 test/main.c -I headers -I libft $(NAME)  -o ./test/run_tests
	#@echo ===============LAUNCHING TESTS=================
	#./test/run_tests