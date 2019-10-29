CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_handleflag.c srcs/ft_printf.c srcs/ft_printf_data_size.c srcs/toputinlib.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)

NAME = libftprintf.a

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I headers -I libft/.

all: $(NAME)

$(NAME) : $(OBJS)
	cd libft && make bonus
	ar rcs $(NAME) $(OBJS) libft/libft.a
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
	$(CC) $(CFLAGS) -fsanitize=address -g3 tests/main.c -I headers -I libft $(NAME) libft/libft.a -o ./tests/run_tests
	@echo ===============LAUNCHING TESTS=================
	./tests/run_tests