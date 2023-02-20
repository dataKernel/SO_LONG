NAME  	= 	so_long

FLAGS 	= 	-Wall -Wextra -Werror
CC		= 	gcc

RM 		= 	rm -f

SRCS 	=	./utils/map_utils.c \
			map.c so_long.c

OBJS 	= 	./utils/map_utils.o \
			map.o so_long.o

LIB		= 	-L ./libx_opengl -lmlx -framework OpenGL -framework AppKit -lz

all : $(NAME)
