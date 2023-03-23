#ifndef COLLECTIBLE_H
# define COLLECTIBLE_H

#include "image.h"

typedef struct      s_collectible
{
    t_img   sprite;
    int     posiX;
    int     posiY;
}t_collectible;

t_img   load_collectible(t_win window, char* mapString);
int     get_position_character(char *mapString);

#endif
