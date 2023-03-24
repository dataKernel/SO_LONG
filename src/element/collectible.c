#include "../../include/image.h"
#include "../../include/collectible.h"
#include "../../include/map_checking_utils.h"

t_collectible       load_collectible(t_win window, char *mapString)
{
    t_collectible   collectible;

    collectible.sprite = create_sprite(, window.mlxPtr);
    collectible.posiX = get_position_character(mapString) % check_width_line(mapString);
    collectible.posiY = get_position_character(mapString) / check_width_line(mapString);
    return(collectible);
}

int                 get_position_collectible(char *mapString)
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
