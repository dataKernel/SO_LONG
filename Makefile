###VARS###
NAME  	= 	so_long

FLAGS 	=
CC		= 	gcc

OBJS 	=	src/map/map_checking_utils.o \
			src/element/collectible.o \
			src/events/events_utils.o \
			src/element/character.o \
			src/image/image_utils.o \
			src/map/map_checking.o \
			src/events/events.o \
			src/map/map_utils.o \
			src/image/image.o \
			src/map/map.o \
			src/init.o \
			main.o \

LIB		= 	-L libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

###RULES###
all: $(NAME)

fclean:
	find . -type f -name '*.o' -delete

so_long: $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

src/map/map_checking.o:			src/map/map_checking.c \
								include/map_checking.h \
								include/map_checking.h
								$(CC) src/map/map_checking.c -c -o src/map/map_checking.o $(FLAGS)

src/map/map_checking_utils.o: 	src/map/map_checking_utils.c \
								include/map_checking_utils.h \
								include/image_utils.h \
								include/image.h \
								libx_opengl/mlx.h
								$(CC) src/map/map_checking_utils.c -c -o src/map/map_checking_utils.o $(FLAGS)

src/init.o :					src/init.c \
								include/init.h \
								include/map_checking_utils.h \
								include/collectible.h \
								include/image_utils.h \
								include/image.h \
								include/character.h \
								libx_opengl/mlx.h
								$(CC) src/init.c -c -o src/init.o $(FLAGS)

src/map/map.o: 					src/map/map.c \
								include/map_checking_utils.h \
								include/image_utils.h \
								include/map_utils.h \
								include/image.h \
								include/map.h \
								libx_opengl/mlx.h
								$(CC) src/map/map.c -c -o src/map/map.o $(FLAGS)

src/map/map_utils.o: 			src/map/map_utils.c \
								include/map_checking_utils.h \
								include/map_utils.h \
								libx_opengl/mlx.h
								$(CC) src/map/map_utils.c -c -o src/map/map_utils.o $(FLAGS)

src/image/image.o:				src/image/image.c \
								include/image_utils.h \
								include/image.h \
								libx_opengl/mlx.h
								$(CC) src/image/image.c -c -o src/image/image.o $(FLAGS)


src/image/image_utils.o:		src/image/image_utils.c \
								include/image_utils.h \
								include/image.h \
								libx_opengl/mlx.h
								$(CC) src/image/image_utils.c -c -o src/image/image_utils.o $(FLAGS)

src/element/character.o:		src/element/character.c \
								include/map_checking_utils.h \
								include/character.h \
								include/image.h \
								libx_opengl/mlx.h
								$(CC) src/element/character.c -c -o src/element/character.o $(FLAGS)

src/element/collectible.o:		src/element/collectible.c \
								include/map_checking_utils.h \
								include/collectible.h \
								include/image.h \
								libx_opengl/mlx.h
								$(CC) src/element/collectible.c -c -o src/element/collectible.o $(FLAGS)

src/events/events.o:			src/events/events.c \
								include/map_checking_utils.h \
								include/events_utils.h \
								include/collectible.h \
								include/character.h \
								include/events.h \
								include/image.h \
								include/map.h \
								libx_opengl/mlx.h
								$(CC) src/events/events.c -c -o src/events/events.o $(FLAGS)

src/events/events_utils.o: 		src/events/events_utils.c \
								include/events_utils.h \
								include/character.h \
								include/events.h \
								include/image.h \
								include/map.h \
								libx_opengl/mlx.h
								$(CC) src/events/events_utils.c -c -o src/events/events_utils.o $(FLAGS)

main.o: main.c
	$(CC) main.c -c -o main.o $(FLAGS)
