NAME = cub3D

SRC = main.c  ./utils1/ft_putstr_fd.c ./utils1/ft_strcmp.c ./utils1/ft_split_2.c \
	 ./parsing/data_init.c ./parsing/checks.c ./parsing/identefiers_utils1.c ./parsing/identefiers_utils2.c ./parsing/identefiers_utils3.c ./parsing/identefiers.c ./parsing/free.c \
	./utils1/print_error.c ./utils1/ft_atoi.c ./utils1/ft_strlen2.c \
	./draw/draw.c ./draw/init.c ./draw/utils1.c ./draw/castRays.c ./draw/draw3d.c ./draw/keys.c ./draw/moves.c ./draw/textures.c \
	 ./get-next-line/get_next_line_utils.c ./get-next-line/get_next_line.c \
	 ./map/colors.c ./map/make_it_square.c ./map/map_utils.c  ./map/map_utils2.c ./map/map_utils3.c ./map/map_utils4.c ./map/map.c ./draw/walls_checkers.c\

OBJ = $(SRC:.c=.o)

CFALGS = -Wall -Wextra -Werror -g3 #-fsanitize=address -g3

CC = cc

all : $(NAME)

%.o : %.c
	$(CC) -c $(CFALGS) -I/usr/include -Imlx_linux -O3 $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFALGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : clean fclean all

build : all clean
	clear

.PHONY : all clean fclean re build

.SECONDARY : $(OBJ)