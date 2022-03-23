# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 13:19:41 by jae               #+#    #+#              #
#    Updated: 2021/01/29 13:19:43 by jae              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	libasm.a
NASM	=	nasm
FLAGS	=	-f macho64
INC		=	includes/libasm.h
SRC		=	srcs/ft_write.s \
			srcs/ft_strlen.s	\
			srcs/ft_read.s		\
			srcs/ft_strcmp.s	\
			srcs/ft_strcpy.s	\
			srcs/ft_strdup.s
OBJ		=	$(SRC:.s=.o)
OBJ_BONUS	=	$(BONUS:.s=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o		:	%.s
			$(NASM) -I$(INC) $(FLAGS) $< -o $@

clean	:
			rm -rf $(OBJ) $(OBJ_BONUS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

test	:	re
			$(CC) -o test tester.c -L. -lasm
			./test

.PHONY: all, clean, fclean, re
