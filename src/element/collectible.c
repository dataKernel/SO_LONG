#include "../../include/collectible.h"
#include "../../include/map_checking_utils.h"

void    load_collectible_on_map(t_win window, t_map map)
{
    int     index;
    
    index = 0;
    while(map.content[index])
    {
        if(map.content[index] == 'H')
            load_collectible(window, map, COLLECTIBLE_HP_PATH, index);
        else if(map.content[index] == 'M')
            load_collectible(window, map, COLLECTIBLE_MANA_PATH, index);
        index++;
    }
}

void    load_collectible(t_win window, t_map map, char *spritePath, int index)
{
    t_coll      collectible;
    int         x;
    int         y;
    
    collectible.sprite = create_sprite(spritePath, window.mlxPtr);
    collectible.posiX = get_position_collectible(map, index) % map.width;
    collectible.posiY = get_position_collectible(map, index) / map.width;
    x = collectible.posiX * 40;
    y = collectible.posiY * 40 + 42;
    mlx_put_image_to_window(window.mlxPtr, window.winPtr, collectible.sprite.imgPtr, x, y);
}

int     get_position_collectible(t_map map, int index)
{    
    while(map.content[index])
    {
        if(map.content[index] == 'H' || map.content[index] == 'M')
            return(index);
        index++;
    }
    return(0);
}

int     check_collectible_nbr(t_map map)
{
    int     result;
    int     i;
    
    i = 0;
    result = 0;
    while(map.content[i])
    {
        if(map.content[i] == COLLECTIBLE)
            result++;
        i++;
    }
    return(result);
}