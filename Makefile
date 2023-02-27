###VAR###
NAME  	= 	so_long

FLAGS 	= 	-Wall -Wextra -Werror
CC		= 	gcc

RM 		= 	rm -f

SRCS 	=	main.c \
			src/map/map_checking.c src/map/map_checking_utils.c \
			src/image/image.c

OBJS 	= 	main.o \
			src/map/map_checking.o src/map/map_checking_utils.o \
			src/image/image.o

LIB		= 	-L libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

###RULES###
all: $(NAME)

fclean:
	rm -rf *.o

main.o: main.c
	$(CC) $(SRCS) -c -o $(OBJS) $(FLAGS)

map_checking.o: src/map/map_checking.c include/map_checking.h include/map_checking_utils.h
	$(CC) src/map/map_checking.c -c -o src/map/map_checking.o $(FLAGS)

map/map_checking_utils.o: src/map/map_checking_utils.c src/map/map_checking_utils.h
	$(CC) src/map/map_checking_utils.c -c -o map/map_checking_utils.o $(FLAGS)

image.o : src/image/image.c include/image.h
	$(CC) src/image/image.c -c -o src/image/image.o $(FLAGS)

so_long:  main.o
	$(CC) main.o $(LIB) -o $(NAME)
