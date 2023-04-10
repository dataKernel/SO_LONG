#ifndef MAP_UTILS_H
# define MAP_UTILS_H

#include "map.h"

t_map   generate_matrix_map(char *mapString);
void    rm_backslash_mapstring(char *map, char **dst);
char    *rm_player_mapstring(char *map);

#endif
