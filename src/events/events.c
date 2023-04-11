#include "../../include/events.h"
#include "../../include/map_utils.h"
#include "../../include/map_checking_utils.h"
#include <stdio.h>

/*
int     hook_character(int keycode, t_events *events)
{
    void    *mlx;
    void    *win;
    char    *map;
    int     widthLine;
    int     x;
    int     y;

    move_char(&(events->character), map, widthLine, keycode, mlx);
    x = events->character.posiX * 40;
    y = events->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlx, win, events->map.imgPtr, 0, 0);
    mlx_put_image_to_window(mlx, win, events->character.sprite.imgPtr, x, y);
    free(map);
    return(0);
}
*/

/*
void    move_char(t_char *character, char *map, int widthLine, int keycode, void *mlx)
{
    int     posi;

    posi = check_index_from_matrix(character->posiX, character->posiY, widthLine);
    if(keycode == TOP && map[posi - widthLine] == SPACE)
    {
        character->sprite = create_sprite(CHAR_TOP_1_PATH, mlx);
        character->posiY--;
    }
    else if(keycode == DOWN && map[posi + widthLine] == SPACE)
    {
        character->sprite = create_sprite(CHAR_DOWN_1_PATH, mlx);
        character->posiY++;
    }
    else if(keycode == RIGHT && map[posi + 1] == SPACE)
    {
        character->sprite = create_sprite(CHAR_RIGHT_1_PATH, mlx);
        character->posiX++;
    }
    else if(keycode == LEFT && map[posi - 1] == SPACE)
    {
        character->sprite = create_sprite(CHAR_LEFT_1_PATH, mlx);
        character->posiX--;
    }
}
*/

int     check_key(int keycode)
{
    printf("touche pressée --> %i\n", keycode);
    return(0);
}
