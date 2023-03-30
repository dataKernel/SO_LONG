#include "../../include/events.h"
#include "../../include/map_utils.h"
#include "../../include/map_checking_utils.h"
#include <stdio.h>

int     hook_character(int keycode, t_events *events)
{
    void    *mlx;
    void    *win;
    char    *map;
    int     widthLine;
    int     x;
    int     y;

    mlx = events->window.mlxPtr;
    win = events->window.winPtr;
    map = NULL;
    widthLine = check_width_line(events->mapString);
    rm_backslash_mapstring(events->mapString, &map);
    move_char(&(events->character), map, widthLine, keycode);
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    return(0);
}

void    move_char(t_char *character, char *map, int widthLine, int keycode)
{
    int     posi;

    posi = check_index_from_matrix(character->posiX, character->posiY, widthLine);
    if(keycode == TOP && (map[posi - widthLine] == SPACE || map[posi - widthLine] == PLAYER))
        character->posiY--;
    else if(keycode == DOWN && (map[posi + widthLine] == SPACE || map[posi + widthLine] == PLAYER))
        character->posiY++;
    else if(keycode == RIGHT && (map[posi + 1] == SPACE || map[posi + 1] == PLAYER))
        character->posiX++;
    else if(keycode == LEFT && (map[posi - 1] == SPACE || map[posi - 1] == PLAYER))
        character->posiX--;
}

/*int     check_key(int keycode)
{
    printf("touche pressée --> %i\n", keycode);
    return(0);
}*/
