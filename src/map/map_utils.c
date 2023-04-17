#include "../../include/map_checking_utils.h"
#include "../../include/map_utils.h"
#include "../../include/map.h"
#include <stdlib.h>
#include <stdio.h>

char    *rm_player_mapstring(char *map)
{
    int     randConso;
    int     i;

    i = 0;
    while(map[i])
    {
        randConso = rand_sprites(COLLECTIBLE_HP, COLLECTIBLE_MANA);
        if(map[i] == PLAYER)
            map[i] = SPACE;
        else if(map[i] == COLLECTIBLE)
        {
            if(randConso == COLLECTIBLE_HP)
                map[i] = 'H';
            else if(randConso == COLLECTIBLE_MANA)
                map[i] = 'M';
        }
        i++;
    }
    return(map);
}

void    rm_backslash_mapstring(char *map, char **dst)
{
    int     sizeMap;
    int     i;
    int     j;

    i = 0;
    while(map[i])
        i++;
    map = rm_player_mapstring(map);
    sizeMap = (i - check_height_column(map));
    *dst = (char *)malloc(sizeof(char) * (sizeMap + 1));
    i = 0;
    j = 0;
    while(map[i])
    {
        (*dst)[j] = map[i];
        i++;
        j++;
        if(map[i] == '\n')
            i++;
    }
    (*dst)[j] = '\0';
}

void    init()
{
    
}