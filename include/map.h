#ifndef MAP_H
# define MAP_H

#include "image.h"

int         get_position_character(char *mapString);
t_img       generate_map(char *pathMap, t_win window);
void        generate_wall_top(t_img map, t_img *spriteTabPtr);
void        generate_map_content(char *mapString, t_img map, t_img *spriteTabPtr);

#endif
