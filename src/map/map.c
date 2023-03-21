#include <stdio.h>

#include "../../include/map_checking_utils.h"
#include "../../include/image_utils.h"
#include "../../include/map.h"

//fonction pr generer le random sur les sprites
//(...)

int     get_position_character(char *mapString)
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

void    generate_wall_top(t_img map, t_img *spriteTabPtr)
{
    int     line;

    line = 0;
    while(line < map.width)
    {
        copy_sprite_in_image(spriteTabPtr[WALL_TOP], map, 0 + line, 0);
        line += 40;
    }
}

void    generate_map_content(char *mapString, t_img map, t_img *spriteTabPtr)
{
    int     height;
    int     line;
    int     i;

    i = check_width_line(mapString);
    height = spriteTabPtr[WALL_TOP].height;
    while(height < map.height)
    {
    	line = 0;
    	while(line < map.width)
    	{
            if(mapString[i] == SPACE || mapString[i] == PLAYER)
    		    copy_sprite_in_image(spriteTabPtr[GROUND_1], map, line, height);
            else if(mapString[i] == WALL)
                copy_sprite_in_image(spriteTabPtr[WALL_TREE_2], map, line, height);
            else if(mapString[i] == COLLECTIBLE)
                copy_sprite_in_image(spriteTabPtr[RESSOURCE_1], map, line, height);
            else if(mapString[i] == EXIT)
                copy_sprite_in_image(spriteTabPtr[EXIT_1], map, line, height);
            if(mapString[i] != '\n')
                line += 40;
            i++;
        }
    	height += 40;
    }
}


t_img    generate_map(char *mapString, t_win window)
{
    t_img   *spriteTabPtr;
    t_img   map;

    map = create_image(window.width, window.height, window.mlxPtr);
    spriteTabPtr = load_sprite(window.mlxPtr);
    generate_wall_top(map, spriteTabPtr);
    generate_map_content(mapString, map, spriteTabPtr);
    free(spriteTabPtr);

    return(map);
}
