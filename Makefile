NAME=libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= ft_printf.c \
		make_buffer.c \
		input_info.c \
		substitute_and_print.c \
		string_substitution.c \
		change_to_result.c \
		change_to_result2.c \
		etc.c \
		libft_util.c \
		libft_util2.c \
		etc2.c
BNS_SRCS= ft_printf_bonus.c \
		make_buffer_bonus.c \
		input_info_bonus.c \
		substitute_and_print_bonus.c \
		string_substitution_bonus.c \
		change_to_result_bonus.c \
		change_to_result2_bonus.c \
		etc_bonus.c \
		libft_util_bonus.c \
		libft_util2_bonus.c \
		etc2_bonus.c
ifdef FLAG_BONUS
    OBJS = $(BNS_SRCS:%.c=%.o)
else
    OBJS = $(SRCS:%.c=%.o)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I .
bonus   :  
	make fclean FLAG_BONUS=1 all
clean   :
	rm -f *.o
fclean  :   clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
