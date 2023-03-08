# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 13:24:23 by gkhaishb          #+#    #+#              #
#    Updated: 2023/02/09 13:24:26 by gkhaishb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)
	   
HEADER = ft_printf.h

OBJS = $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

%.o : %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(HEADER) $(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean all

.PHONY:			all clean fclean re
