#include "../../include/map_checking_utils.h"
#include "../../include/map_utils.h"
#include <stdlib.h>
#include <stdio.h>

char    *rm_player_mapstring(char *map)
{
    int     i;

    i = 0;
    while(map[i])
    {
        if(map[i] == PLAYER)
            map[i] = SPACE;
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