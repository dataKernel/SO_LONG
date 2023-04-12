#include "../../include/events_utils.h"

void    move_char_position_top(t_events *events)
{
    events->character.sprite = create_sprite(CHAR_TOP_1_PATH, events->window.mlxPtr);
    events->character.posiY--;
}

void    move_char_position_down(t_events *events)
{
    events->character.sprite = create_sprite(CHAR_DOWN_1_PATH, events->window.mlxPtr);
    events->character.posiY++;
}

void    move_char_position_right(t_events *events)
{
    events->character.sprite = create_sprite(CHAR_RIGHT_1_PATH, events->window.mlxPtr);
    events->character.posiX++;
}

void    move_char_position_left(t_events *events)
{
    events->character.sprite = create_sprite(CHAR_LEFT_1_PATH, events->window.mlxPtr);
    events->character.posiX--;
}