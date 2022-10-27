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
BNS_SRCS= ft_printf.c
OBJS=$(SRCS:%.c=%.o)
BNS_OBJS=$(BNS_SRCS:%.c=%.o)
ifdef FLAG_BONUS
    TOTAL_OBJS = $(OBJS) $(BNS_OBJS)
else
    TOTAL_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I .
bonus   :  
	make FLAG_BONUS=1 all
clean   :
	rm -f $(OBJS) $(BNS_OBJF)
fclean  :   clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re libft
