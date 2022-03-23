NAME	=	cub3d

SRCS	=	main.c \
			key.c \
			parser_utils.c \
			parser_details.c \
			parser.c \
			map_generator.c \
			draw.c \
			bmp.c \
			mapcheck.c \
			sprite.c \
			draw_sprite.c \
			init.c \
			move.c\
			draw_wall.c \
			ray.c

all:	$(NAME)

$(NAME):
	@$(MAKE) -C ./ft_printf all
	gcc ${SRCS} -L ./mlx -lmlx -L ./ft_printf -lftprintf -L ./ft_printf/libft -lft -framework OpenGL -framework AppKit -o cub3d

clean	:
	@$(MAKE) -C ./ft_printf clean

fclean	:
	@$(MAKE) -C ./ft_printf fclean
	rm -rf cub3d
re :
	@$(MAKE) fclean all
