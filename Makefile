# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2018/03/06 14:44:07 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	woody_woodpacker
SRCS		=	encryption/encryption.c \
				packer/main.c \
				packer/loader.c \
				packer/packer.c \
				utils/memory.c \
				utils/elf.c \
				woody.c
INCLUDES	=	./includes
SRCSPATH	=	./srcs/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDES_O	=	-I $(INCLUDES) -I $(LIBFT)/includes
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C srcs/template
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<

clean:
	make -C srcs/template clean
	rm -rf $(OBJS)

fclean:			clean
	make -C srcs/template fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
