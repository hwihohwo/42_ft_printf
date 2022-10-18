NAME=libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= ft_printf.c \
		make_buffer.c \
		input_info.c \
		check_and_substitution.c \
		string_substitution.c \
		change_to_result.c \
		change_to_result2.c \
		etc.c
OBJS=$(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ libft/$^
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I .
clean   :
	rm -f $(OBJS)
fclean  :   clean
	rm -f $(NAME)
libft :
	cd libft; make
re : fclean all
.PHONY : all clean fclean re libft
