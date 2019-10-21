CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c srcs/ft_handleflag.c srcs/tohex.c
OBJS = $(SRCS:srcs/%.c=objs/%.o)

NAME = libftprintf.a

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I headers

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus

test : bonus
	$(CC) $(CFLAGS) -fsanitize=address -g3 tests/main.c -I headers $(NAME) -o ./tests/run_tests
	@echo ===============LAUNCHING TESTS=================
	./tests/run_tests