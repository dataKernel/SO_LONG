#include "../../include/collectible.h"
#include "../../include/map_checking_utils.h"

void    put_collectible_on_map(t_gameState *events)
{
    int     index;
    
    index = 0;
    while(events->map.content[index])
    {
        if(events->map.content[index] == 'H')
            put_collectible(events->window, events->map, &events->collectibleSprite[0], index);
        else if(events->map.content[index] == 'M')
            put_collectible(events->window, events->map, &events->collectibleSprite[1], index);
        index++;
    }
}

void    put_collectible(t_win window, t_map map, t_img *sprite, int index)
{
    int         x;
    int         y;
    
    x = get_position_collectible(map, index) % map.width;
    y = get_position_collectible(map, index) / map.width;
    x *= 40;
    y =  y * 40 + 42;
    mlx_put_image_to_window(window.mlxPtr, window.winPtr, sprite->imgPtr, x, y);
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