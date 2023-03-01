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

bool check_position_libre(char *str, int position);
char    *read_map(char *path);
int     get_index(int y, int x, int width);
int		check_width_line(char *str);

#endif
