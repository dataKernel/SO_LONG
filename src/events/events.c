#include "../../include/map_checking_utils.h"
#include "../../include/events_utils.h"
#include "../../include/events.h"
#include <stdio.h>

int     hook_character(int keycode, t_events *events)
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;
    
    mlx = events->window.mlxPtr;
    win = events->window.winPtr;
    move_char(keycode, events);
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->mapImg.imgPtr, 0, 0);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    return(0);
}

void    move_char(int direction, t_events *events)
{
    if(direction == TOP)
        move_char_position_top(events);
    else if(direction == DOWN)
        move_char_position_down(events);
    else if(direction == RIGHT)
        move_char_position_right(events);
    else if(direction == LEFT)
        move_char_position_left(events);
}