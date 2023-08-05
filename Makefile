NAME = cub3D

LIBFT = ./parsing/libft/

MLX = libmlx.a 

CC = gcc 

#FSANITIZE = -fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit


SOURCES =	./parsing/cub3D.c \
			./parsing/parsing_file.c \
			./parsing/reading_map.c \
			./parsing/ft_print.c \
			./parsing/check_map.c \
			./parsing/check_player.c \
			./parsing/check_null.c \
			./parsing/color_textur.c \
			./parsing/map_error.c \
			./raycasting/cleaner.c \
			./raycasting/engine.c \
			./raycasting/engine_utils.c \
			./raycasting/init_data.c \
			./raycasting/input.c \
			./raycasting/main.c \
			./raycasting/minimap_engine.c \
			./raycasting/moves_utils.c \
			./raycasting/moves.c \
			./raycasting/minimap_utils.c \
			./raycasting/text.c \
			./raycasting/utils.c \
			./raycasting/player_pos.c


OBJ = $(SOURCES:.c=.o)

LIBS = -L -lmlx -lm -lbsd -lX11 -lXext 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)libft.a
	$(CC) $(FSANITIZE) $(CFLAGS) ${MLX} $(LIBFT)libft.a -o $(NAME) $(OBJ) 
	echo "Compilation done"

$(LIBFT)libft.a :
	@make bonus -C $(LIBFT)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)
	echo "Clean done"

fclean: clean
	rm -f $(NAME) 
	@make fclean -C $(LIBFT)
	echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re

