#ifndef COLLECTIBLE_H
# define COLLECTIBLE_H

#include "image.h"
#include "map.h"

typedef struct      s_collectible
{
    t_img   sprite;
    int     nbr;
    int     posiX;
    int     posiY;
}t_coll;

void    load_collectible_on_map(t_win window, t_map map, char *spritePath);
void    load_collectible(t_win window, t_map map, char *spritePath, int index);
int     get_position_collectible(t_map map, int index);
int     check_collectible_nbr(t_map map);

#endif
