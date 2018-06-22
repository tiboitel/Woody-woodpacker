# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2018/06/02 20:10:04 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	woody_woodpacker
SRCS		=	encryption/encryption.c \
				packer/main.c \
				packer/loader.c \
				packer/packer.c \
				utils/memory.c \
				utils/elf.c \
				utils/syscall.c \
				woody.c
INCLUDES	=	./includes
SRCSPATH	=	./srcs/
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Wno-deprecated-declarations
INCLUDES_O	=	-I $(INCLUDES) -I $(LIBFT)/includes
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
#	@C_INCLUDE_PATH=~/.brew/include/elf
	@make -C srcs/template
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) srcs/encryption/tea.o

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<

#install:
#	@mkdir -p ~/.brew/include/
#	@mkdir -p ~/.brew/include/elf/
#	@curl https://raw.github.com/gist/3885346/elf.h | tee ~/.brew/include/elf/elf.h

clean:
	make -C srcs/template clean
	rm -rf $(OBJS)

fclean:			clean
	make -C srcs/template fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
