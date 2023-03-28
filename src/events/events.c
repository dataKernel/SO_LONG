#include "../../include/events.h"
#include "../../include/image.h"
#include "../../include/map_checking_utils.h"
#include <stdio.h>

int     moove_char(int keycode, t_events *events)
{
    void    *mlx;
    void    *win;
    int     posi;
    int     x;
    int     y;
    //posi = check_index_from_matrix(events->character.posiX, events->character.posiY, map);
    mlx = events->window.mlxPtr;
    win = events->window.winPtr;
    if(keycode == TOP)
        events->character.posiY--;
    else if(keycode == DOWN)
        events->character.posiY++;
    else if(keycode == RIGHT)
        events->character.posiX++;
    else if(keycode == LEFT)
        events->character.posiX--;
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);

    return(0);
}

int     check_key(int keycode)
{
    printf("touche pressée --> %i\n", keycode);
    return(0);
}
