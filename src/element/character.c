#include "../../include/image.h"
#include "../../include/character.h"
#include "../../include/map_checking_utils.h"

t_char      load_character(t_win window, char *mapString, char *spritePath)
{
    t_char     character;

    character.sprite = create_sprite(spritePath, window.mlxPtr);
    character.posiX = get_position_character(mapString) % check_width_line(mapString);
    character.posiY = get_position_character(mapString) / check_width_line(mapString);
    return(character);
}

int         get_position_character(char *mapString)
{
    int     countBackSlash;
    int     i;

    i = 0;
    countBackSlash = 0;
    while(mapString[i] != PLAYER)
    {
        if(mapString[i] == '\n')
        countBackSlash++;
        i++;
    }
    return(i - countBackSlash);
}
