# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2017/08/10 21:32:41 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	woody_woodpacker
SRCS		=	main.c \
				loader.c \
				encryption.c
INCLUDES	=	./includes
LIBFT		=	./libft
SRCSPATH	=	./srcs/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address
INCLUDES_O	=	-I $(INCLUDES) -I $(LIBFT)/includes
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean:			clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
