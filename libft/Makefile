# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 19:35:10 by seonghwc          #+#    #+#              #
#    Updated: 2022/07/12 20:25:16 by seonghwc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = libft.a
SRCS                    = ft_atoi.c \
                      ft_bzero.c \
                      ft_calloc.c \
                      ft_isalnum.c \
                      ft_itoa.c \
                      ft_isalpha.c \
                      ft_isascii.c \
                      ft_isdigit.c \
                      ft_isprint.c \
                      ft_memchr.c \
                      ft_memcmp.c \
                      ft_memcpy.c \
                      ft_memmove.c \
                      ft_memset.c \
                      ft_split.c \
                      ft_strchr.c \
                      ft_strdup.c \
                      ft_striteri.c \
                      ft_strlcat.c \
                      ft_strlcpy.c \
                      ft_strlen.c \
                      ft_strncmp.c \
                      ft_strnstr.c \
                      ft_strrchr.c \
                      ft_strjoin.c \
                      ft_strtrim.c \
                      ft_strmapi.c \
                      ft_substr.c \
                      ft_tolower.c \
                      ft_toupper.c \
                      ft_putchar_fd.c \
                      ft_putstr_fd.c \
                      ft_putendl_fd.c \
                      ft_putnbr_fd.c
BNS_SRCS                = ft_lstsize.c \
                    ft_lstadd_front.c \
                    ft_lstclear.c \
                    ft_lstdelone.c \
                    ft_lstiter.c \
                    ft_lstlast.c \
                    ft_lstmap.c \
                    ft_lstadd_back.c \
                    ft_lstnew.c
OBJS                    = $(SRCS:%.c=%.o)
BNS_OBJS                = $(BNS_SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror
ifdef FLAG_BONUS
    TOTAL_OBJS = $(OBJS) $(BNS_OBJS)
else
    TOTAL_OBJS = $(OBJS)
endif

$(NAME)     :   $(TOTAL_OBJS)
	ar rc $@ $^
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I .
all :   $(NAME)
bonus   :  
	make FLAG_BONUS=1 all
clean   :
	rm -f $(OBJS) $(BNS_OBJS)
fclean  :   clean
	rm -f $(NAME)
re  :   fclean all
.PHONY  :   all clean fclean re