#ifndef MAP_CHECKING_UTILS_H
# define MAP_CHECKING_UTILS_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define SPACE '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

bool    check_position_libre(char*, int);
char    *read_map(char *);
int     get_index(int, int, int);
int     check_width_line(char *);

#endif
