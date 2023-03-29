#ifndef EVENTS_H
# define EVENTS_H

# include "image.h"
# include "character.h"

# define TOP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123


typedef struct      s_events
{
    t_char  character;
    t_win   window;
    t_img   map;
    char    *mapString;
}t_events;

void    move_char(t_char *character, char *map, int widthLine, int keycode);
int     hook_character(int keycode, t_events *events);
int     check_key(int keycode);

#endif
