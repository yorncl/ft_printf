CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_handleflag.c srcs/ft_printers1.c srcs/ft_printers2.c srcs/ft_printers_utils.c srcs/ft_printf.c srcs/toputinlib1.c srcs/toputinlib2.c
SRCS_LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_intlen.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_max.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_min.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
OBJS = $(SRCS:srcs/%.c=srcs/%.o) $(SRCS_LIBFT:libft/%.c=libft/%.o)

NAME = libftprintf.a

srcs/%.o: srcs/%.c
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
testperso : bonus
	$(CC) $(FLAGS) -fsanitize=address -g3 test/perso.c -I headers -I libft $(NAME)  -o ./test/run_tests
