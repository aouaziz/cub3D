NAME = Cub3d

BNAME = Cub3d_Bonus

MLX_DIR = minilibx-linux

LIBFT = ./parsing/libft/

MLX = libmlx.a 

CC = gcc
FSANITIZE = -fsanitize=address -g

#CFLAGS = -Wall -Wextra -Werror 

INC_DIR = -I./minilibx-linux

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

BSOURCES =	./Bonus/parsing/cub3D.c \
			./Bonus/parsing/parsing_file.c \
			./Bonus/parsing/reading_map.c \
			./Bonus/parsing/ft_print.c \
			./Bonus/parsing/check_map.c \
			./Bonus/parsing/check_player.c \
			./Bonus/parsing/check_null.c \
			./Bonus/parsing/color_textur.c \
			./Bonus/parsing/map_error.c \
			./Bonus/main.c \
			./raycasting/cleaner.c \
			./raycasting/engine.c \
			./raycasting/engine_utils.c \
			./raycasting/init_data.c \
			./raycasting/input.c \
			./raycasting/minimap_engine.c \
			./raycasting/moves_utils.c \
			./raycasting/moves.c \
			./raycasting/minimap_utils.c \
			./raycasting/text.c \
			./raycasting/utils.c \


OBJ = $(SOURCES:.c=.o)

BOBJ = $(BSOURCES:.c=.o)

LIBS = -L$(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)libft.a
	$(CC) $(FSANITIZE) $(CFLAGS) ${MLX} $(LIBFT)libft.a -o $(NAME) $(OBJ) 
	echo "Compilation done"

$(LIBFT)libft.a :
	@make bonus -C $(LIBFT)

bonus:$(BNAME)

$(BNAME): $(BOBJ) $(LIBFT)libft.a
	$(CC) $(FSANITIZE) $(CFLAGS) ${MLX} $(LIBFT)libft.a -o $(BNAME) $(BOBJ) 
	echo "Bonus Compilation done"


clean:
	rm -f $(OBJ) $(BOBJ)
	@make clean -C $(LIBFT)
	echo "Clean done"

fclean: clean
	rm -f $(NAME) $(BNAME)
	@make fclean -C $(LIBFT)
	echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re

