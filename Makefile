CC = gcc
CFLAGS = -Wall -Werror -Wextra

HEADERS = headers/ft_printf.h headers/converters.h
SRCS = srcs/tohex.c
OBJS = $($(SRCS):srcs/%.c : objs/%.o)

NAME = libftprintf.a

objs/%.o : srcs/%.c

all: $(NAME)

$(NAME) : $(OBJS)
	echo a
	ar rcs $(OBJS) libftprintf.a

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus


test : bonus