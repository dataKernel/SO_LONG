#include "../../include/map_checking_utils.h"
#include "../../include/events_utils.h"

void    move_char_position_top(t_gameState *events)
{
    char    *map;
    int     position;
    int     w;
    int     x;
    int     y;
    
    map = events->map.content;
    w = events->map.width;
    x = events->character.posiX;
    y = events->character.posiY;
    position = check_index_from_matrix(x, y, w);
    events->character.sprite = create_sprite(CHAR_TOP_1_PATH, events->window.mlxPtr);
    if(map[position - w] == SPACE || map[position - w] == 'H' || map[position - w] == 'M' || map[position - w] == EXIT)
        events->character.posiY--;
}

void    move_char_position_down(t_gameState *events)
{
    char    *map;
    int     position;
    int     w;
    int     x;
    int     y;
    
    map = events->map.content;
    w = events->map.width;
    x = events->character.posiX;
    y = events->character.posiY;
    position = check_index_from_matrix(x, y, w);
    events->character.sprite = create_sprite(CHAR_DOWN_1_PATH, events->window.mlxPtr);
    if(map[position + w] == SPACE || map[position + w] == 'H' || map[position + w] == 'M' || map[position + w] == EXIT)
        events->character.posiY++;
}

void    move_char_position_right(t_gameState *events)
{
    char    *map;
    int     position;
    int     w;
    int     x;
    int     y;
    
    map = events->map.content;
    w = events->map.width;
    x = events->character.posiX;
    y = events->character.posiY;
    position = check_index_from_matrix(x, y, w);
    events->character.sprite = create_sprite(CHAR_RIGHT_1_PATH, events->window.mlxPtr);
    if(map[position + 1] == SPACE || map[position + 1] == 'H' || map[position + 1] == 'M' || map[position + 1] == EXIT)
        events->character.posiX++;
}

void    move_char_position_left(t_gameState *events)
{
    char    *map;
    int     position;
    int     w;
    int     x;
    int     y;
    
    map = events->map.content;
    w = events->map.width;
    x = events->character.posiX;
    y = events->character.posiY;
    position = check_index_from_matrix(x, y, w);
    events->character.sprite = create_sprite(CHAR_LEFT_1_PATH, events->window.mlxPtr);
    if(map[position - 1] == SPACE || map[position - 1] == 'H' || map[position - 1] == 'M' || map[position - 1] == EXIT)
        events->character.posiX--;
}