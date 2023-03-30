#include "../../include/map_utils.h"

int     check_map_size(char *map)
{
    return(0);
}

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
    sizeMap = (i - slash);
    *dst = (char *)malloc(sizeof(char) * (sizeMap + 1));
    if(*dst == NULL)
        printf("ERROR_MALLOC\n"); //comment return code erreur apres malloc sur une func de type void
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
