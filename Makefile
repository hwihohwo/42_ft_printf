NAME=libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS= ./srcs/ft_printf.c \
		./srcs/make_buffer.c \
		./srcs/input_info.c \
		./srcs/substitute_and_print.c \
		./srcs/string_substitution.c \
		./srcs/change_to_result.c \
		./srcs/change_to_result2.c \
		./srcs/etc.c \
		./srcs/libft_util.c \
		./srcs/libft_util2.c \
		./srcs/etc2.c
BNS_SRCS= ./bns_srcs/ft_printf_bonus.c \
		./bns_srcs/make_buffer_bonus.c \
		./bns_srcs/input_info_bonus.c \
		./bns_srcs/substitute_and_print_bonus.c \
		./bns_srcs/string_substitution_bonus.c \
		./bns_srcs/change_to_result_bonus.c \
		./bns_srcs/change_to_result2_bonus.c \
		./bns_srcs/etc_bonus.c \
		./bns_srcs/libft_util_bonus.c \
		./bns_srcs/libft_util2_bonus.c \
		./bns_srcs/etc2_bonus.c
ifdef FLAG_BONUS
    OBJS = $(BNS_SRCS:%.c=%.o)
else
    OBJS = $(SRCS:%.c=%.o)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .
bonus   :  
	make fclean FLAG_BONUS=1 all
clean   :
	rm -f ./srcs/*.o ./bns_srcs/*.o
fclean  :   clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
