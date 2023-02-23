###VAR###
NAME  	= 	so_long

FLAGS 	= 	-Wall -Wextra -Werror
CC		= 	gcc

RM 		= 	rm -f

SRCS 	=	./utils/map_utils.c \
			map.c so_long.c

OBJS 	= 	./utils/map_utils.o \
			map.o so_long.o

LIB		= 	-L ./libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

###RULES###
all: 		$(NAME)
fclean: 	*.o utils/*.o
	rm -f *.o utils/*.o
map.o:		map.c map.h utils/map_utils.h
	$(CC) map.c -c -o map.o $(FLAGS)
so_long.o:		so_long.c map.h utils/map_utils.h
	$(CC) so_long.c -c -o so_long.o $(FLAGS)
utils/map_utils.o:		utils/map_utils.c  utils/map_utils.h
	$(CC) utils/map_utils.c -c -o utils/map_utils.o $(FLAGS)
so_long: map.o so_long.o utils/map_utils.o
	$(CC) map.o so_long.o utils/map_utils.o $(LIB) -o $(NAME)
