# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:48:27 by tiboitel          #+#    #+#              #
#    Updated: 2018/06/02 19:55:19 by tiboitel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	template
SRCS		=	encryption/encryption.c \
				template/main.c \
				packer/loader.c \
				packer/packer.c \
				utils/memory.c \
				utils/syscall.c
INCLUDES	=	../../includes
SRCSPATH	=	../../srcs/
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Wno-deprecated-declarations
INCLUDES_O	=	-I $(INCLUDES)
SRC			=	$(addprefix $(SRCSPATH), $(SRCS))
OBJS		=	$(SRC:.c=.o)
OSFLAG 		:=
UNAME_S 	:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OSFILE += ../encryption/tea_elf.o
	OSCOMP += nasm -f elf64 ../encryption/tea_elf.s
endif
ifeq ($(UNAME_S),Darwin)
	OSFILE += ../encryption/tea.o
	OSCOMP += nasm -f macho64 ../encryption/tea.s
endif



all:			$(NAME)

$(NAME):		$(OBJS)

	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OSFILE)
	/usr/bin/xxd -i $(NAME) > ../woody.c

%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) -c $<
	$(OSCOMP)

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
