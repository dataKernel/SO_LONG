#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <time.h>
# include "image.h"

typedef struct      s_map
{
    int     width;
    int     height;
    char    *content;
}t_map;

t_map       generate_matrix_map(char *mapString);
t_img       load_map(char *pathMap, t_win window);
void        generate_wall_top(t_img map, t_img *spriteTabPtr);
void        generate_map_content(char *mapString, t_img map, t_img *spriteTabPtr);
int         rand_sprites(int min, int max);

#endif
