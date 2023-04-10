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

//faire un dessin pr se representer la memoire qui est update ici
void    rm_backslash_mapstring(char *map, char **dst)
{
    int     sizeMap;
    int     slash;
    int     i;
    int     j;

    i = 0;
    slash = 0;
    while(map[i])
    {
        if(map[i] == '\n')
            slash++;
        i++;
    }
    map = rm_player_mapstring(map);
    sizeMap = (i - slash);
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
