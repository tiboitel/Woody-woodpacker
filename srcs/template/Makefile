# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2017/11/17 13:21:57 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	template
SRCS		=	encryption/encryption.c \
				template/main.c \
				packer/loader.c \
				packer/packer.c \
				utils/memory.c \
				woody.c
INCLUDES	=	../../includes
LIBFT		=	../../libft
SRCSPATH	=	../../srcs/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDES_O	=	-I $(INCLUDES) -I $(LIBFT)/includes
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft -fsanitize=address
	xxd -i $(NAME) > ../woody.c

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJS)

fclean:			clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
