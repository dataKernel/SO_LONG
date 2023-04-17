#ifndef COLLECTIBLE_H
# define COLLECTIBLE_H

#include "events.h"
#include "image.h"
#include "map.h"

void    put_collectible_on_map(t_events *events);
void    put_collectible(t_win window, t_map map, t_img *sprite, int index);
int     get_position_collectible(t_map map, int index);
int     check_collectible_nbr(t_map map);

#endif
