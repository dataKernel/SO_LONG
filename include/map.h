#ifndef MAP_H
# define MAP_H

#include "image.h"

t_img    generate_map(char *pathMap, t_win window);
void     generate_wall_top(t_img map, t_img *spriteTabPtr, int line);

#endif
