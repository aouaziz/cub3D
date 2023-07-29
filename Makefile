NAME = Cub3d

MLX_DIR = minilibx-linux

LIBFT = ./parsing/libft/

MLX = libmlx.a 

CC = gcc
#FSANITIZE = -fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror 

INC_DIR = -I./minilibx-linux


SOURCES =	./parsing/cub3D.c \
			./parsing/parsing_file.c \
			./parsing/reading_map.c \
			./parsing/ft_print.c \
			./parsing/check_map.c \
			./parsing/check_player.c \
			./parsing/check_null.c \
			./parsing/color_textur.c \
			./parsing/map_error.c \
			./cleaner.c \
			./engine.c \
			./engine_utils.c \
			./init_data.c \
			./input.c \
			./main.c \
			./minimap_engine.c \
			./moves_utils.c \
			./moves.c \
			./minimap_utils.c \
			./text.c \
			./utils.c \

OBJ = $(SOURCES:.c=.o)

LIBS = -L$(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(INC_DIR) $(LIBFT)libft.a -o $(NAME) $(OBJ) $(LIBS)
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

