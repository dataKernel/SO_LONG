#include "../../include/map.h"
#include "../../include/image.h"
#include "../../include/collectible.h"
#include "../../include/map_checking_utils.h"

t_collectible       load_collectible(t_win window, char *mapString)
{
    t_collectible   collectible;
    char            *spritePath;
    int             randCollectible;

    randCollectible = rand_sprites(1, 100);
    if(randCollectible < 80)
        spritePath = COLLECTIBLE_HP_PATH;
    else
        spritePath = COLLECTIBLE_MANA_PATH;
    collectible.sprite = create_sprite(spritePath, window.mlxPtr);
    collectible.posiX = get_position_collectible(mapString) % check_width_line(mapString);
    collectible.posiY = get_position_collectible(mapString) / check_width_line(mapString);
    return(collectible);
}

int                 get_position_collectible(char *mapString)
{
    int      i;
    int      countBackSlash;

    i = 0;
    countBackSlash = 0;
    while(mapString[i] != COLLECTIBLE)
    {
        if(mapString[i] == '\n')
        countBackSlash++;
        i++;
    }
    return(i - countBackSlash);
}
