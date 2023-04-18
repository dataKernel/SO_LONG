#include "../../include/map_checking_utils.h"
#include "../../include/collectible.h"
#include "../../include/events_utils.h"
#include "../../include/events.h"
#include <stdio.h>

int     hook_character(int keycode, t_gameState *events)
{
    void    *mlx;
    void    *win;
    int     position;
    int     x;
    int     y;
    
    mlx = events->window.mlxPtr;
    win = events->window.winPtr;
    move_char(keycode, events);
    position = check_index_from_matrix(events->character.posiX, events->character.posiY, events->map.width);
    if(events->map.content[position] == 'H' || events->map.content[position] == 'M')
    {
        events->character.collectibles++;
        events->map.content[position] = SPACE;
    }
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->mapImg.imgPtr, 0, 0);
    put_collectible_on_map(events);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    return(0);
}

void    move_char(int direction, t_gameState *events)
{
    if(direction == TOP)
    {
        move_char_position_top(events);
        events->character.movesNbr++;
    }
    else if(direction == DOWN)
    {
        move_char_position_down(events);
        events->character.movesNbr++;
    }
    else if(direction == RIGHT)
    {
        move_char_position_right(events);
        events->character.movesNbr++;
    }    
    else if(direction == LEFT)
    {
        move_char_position_left(events);
        events->character.movesNbr++;
    }
    printf("moves: %i\n", events->character.movesNbr);
}