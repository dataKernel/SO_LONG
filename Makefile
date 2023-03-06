###VAR###
NAME  	= 	so_long

FLAGS 	= 	
CC		= 	gcc

RM 		= 	rm -f

SRCS 	=	main.c \
			src/map/map_checking.c src/map/map_checking_utils.c \
			src/image/image.c src/image/image_utils.c

OBJS 	= 	main.o \
			src/map/map_checking.o src/map/map_checking_utils.o \
			src/image/image.o src/image/image_utils.o

LIB		= 	-L libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

###RULES###
all: $(NAME)

fclean:
	rm -rf *.o

so_long: $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

src/map/map_checking.o: src/map/map_checking.c include/map_checking.h include/map_checking_utils.h
	$(CC) src/map/map_checking.c -c -o src/map/map_checking.o $(FLAGS)

src/map/map_checking_utils.o: src/map/map_checking_utils.c include/map_checking_utils.h
	$(CC) src/map/map_checking_utils.c -c -o src/map/map_checking_utils.o $(FLAGS)

src/image/image.o : src/image/image.c include/image.h
	$(CC) src/image/image.c -c -o src/image/image.o $(FLAGS)

src/image/image_utils.o : src/image/image_utils.c include/image_utils.h
	$(CC) src/image/image_utils.c -c -o src/image/image_utils.o $(FLAGS)

main.o: main.c
	$(CC) main.c -c -o main.o $(FLAGS)
