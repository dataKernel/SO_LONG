#include "../../include/events.h"
#include "../../include/image.h"
#include <stdio.h>

int     moove_char(int keycode, t_events *events)
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;

    mlx = events->window.mlxPtr;
    win = events->window.winPtr;
    if(keycode == TOP)
    {
        x = events->character.posiX;
        y = events->character.posiY;
        events->character.posiY--;
        y = events->character.posiY * 40;
        mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
        mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    }
    else if(keycode == DOWN)
    {
        x = events->character.posiX;
        y = events->character.posiY;
        events->character.posiY++;
        y = events->character.posiY * 40;
        mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
        mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    }
    else if(keycode == RIGHT)
    {
        x = events->character.posiX;
        y = events->character.posiY;
        events->character.posiX++;
        x = events->character.posiX * 40;
        mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
        mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    }
    return(0);
}

int     check_key(int keycode)
{
    printf("touche pressée --> %i\n", keycode);
    return(0);
}
