#include "../../include/map_checking_utils.h"
#include "../../include/map_utils.h"
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
    printf("posi: %i\n", events->character.posiX);
    move_char(keycode, events);
    printf("posi: %i\n", events->character.posiX);
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->mapImg.imgPtr, 0, 0);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    return(0);
}

void    move_char(int direction, t_events *events)
{
    t_char  *character;
    char    *map;
    int     position;
    
    character = &(events->character);
    map = events->map.content;
    position = check_index_from_matrix(character->posiX, character->posiY, events->map.width);
    
    if(direction == TOP)
        move_char_position_top(map, character, position);
}

void    move_char_position_top(char *map, t_char *character, int position)
{
    
}









