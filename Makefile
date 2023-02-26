###VAR###
NAME  	= 	so_long

FLAGS 	= 	-Wall -Wextra -Werror
CC		= 	gcc

RM 		= 	rm -f

SRCS 	=	main.c map/map_checking_utils.c map_checking.c

OBJS 	= 	main.o map/map_checking_utils.o map_checking.o

LIB		= 	-L libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

###RULES###
all: $(NAME)

fclean:
	rm -rf *.o

map_checking.o: map/map_checking.c include/map_checking.h include/map_checking_utils.h
	$(CC) map/map_checking.c -c -o map/map_checking.o $(FLAGS)

main.o: main.c
	$(CC) main.c -c -o main.o $(FLAGS)

map/map_checking_utils.o: map/map_checking_utils.o  utils/map_utils.h
	$(CC) utils/map_utils.c -c -o utils/map_utils.o $(FLAGS)

so_long: map.o so_long.o utils/map_utils.o
	$(CC) map.o so_long.o utils/map_utils.o $(LIB) -o $(NAME)
