#ifndef EVENTS_H
# define EVENTS_H

# include "map.h"
# include "image.h"
# include "character.h"

# define TOP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct      t_gameState
{
    t_char  character;
    t_win   window;
    t_img   collectibleSprite[2];
    t_img   mapImg;
    t_map   map;
}t_gameState;

void    move_char(int direction, t_gameState *events);
int     hook_character(int keycode, t_gameState *events);
int     check_key(int keycode);

#endif
