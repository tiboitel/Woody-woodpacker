# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2018/06/02 19:58:11 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hello
SRCS		=	main.c
INCLUDES	=	./includes
SRCSPATH	=	./
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -m32
INCLUDES_O	=	-I $(INCLUDES) -I $(LIBFT)/includes
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
