# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2017/08/23 18:49:32 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hello
SRCS		=	main.c
INCLUDES	=	./includes
SRCSPATH	=	./
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
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
