# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jae <jae@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 02:28:01 by jae               #+#    #+#              #
#    Updated: 2020/07/24 02:28:02 by jae              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar
ARFLAGS			= rcs

NAME			= libftprintf.a
LIBFT_DIR		= libft
LIBFT			= libft/libft.a

SRC				= srcs/main.c \
					srcs/parse.c \
					srcs/util.c \
					srcs/check.c \
					srcs/put_c.c \
					srcs/put_s.c \
					srcs/put_p.c \
					srcs/put_d.c \
					srcs/put_u.c \
					srcs/put_x.c \
					srcs/put_pct.c
BONUSSRC		= bonus/main_bonus.c \
					bonus/parse_bonus.c \
					bonus/util_bonus.c \
					bonus/check_bonus.c \
					bonus/get_bonus.c \
					bonus/put_c_bonus.c \
					bonus/put_s_bonus.c \
					bonus/put_p_bonus.c \
					bonus/put_d_bonus.c \
					bonus/put_u_bonus.c \
					bonus/put_x_bonus.c \
					bonus/put_pct_bonus.c \
					bonus/put_n_bonus.c \
					bonus/put_f_bonus.c \
					bonus/put_g_bonus.c \
					bonus/put_e_bonus.c

OBJ				= $(patsubst %.c, %.o, $(SRC))
BONUSOBJ		= $(patsubst %.c, %.o, $(BONUSSRC))

HDR_DIR			= includes
HDR				= includes/ft_printf.h
BONUSHDR		= includes/ft_printf_bonus.h


.SUFFIXES: .c .o .a
.PHONY: all bonus clean fclean re
.c.o:
	$(CC) -I$(HDR_DIR) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(LIBFT) $(BONUSOBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJ)
	ranlib $(NAME)

bonus : $(LIBFT) $(BONUSOBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJ)
	ranlib $(NAME)

$(OBJ): $(HDR) $(SRC)
$(BONUSOBJ): $(BONUSHDR) $(BONUSSRC)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)
	rm -f $(BONUSOBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
