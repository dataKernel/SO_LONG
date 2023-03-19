#include <stdio.h>

#include "../../include/image_utils.h"
#include "../../include/map.h"
#include "../../include/map_checking_utils.h"

void    generate_wall_top(t_img map, t_img *spriteTabPtr)
{
    int     line;

    line = 0;
    while(line < map.width)
    {
        copy_sprite_in_image(spriteTabPtr[3], map, 0 + line, 0);
        line += spriteTabPtr[3].width;
    }
}

void    generate_map_content(char *mapString, t_img map, t_img *spriteTabPtr)
{
    int     height;
    int     line;
    int     i;

    i = check_width_line(mapString);
    height = spriteTabPtr[3].height;
    while(height < map.height)
    {
    	line = 0;
    	while(line < map.width)
    	{
            if(mapString[i] == SPACE)
    		    copy_sprite_in_image(spriteTabPtr[GROUND_1], map, 0 + line, 0 + height);
            else if(mapString[i] == WALL)
                copy_sprite_in_image(spriteTabPtr[WALL_TREE_2], map, 0 + line, 0 + height);
            else if(mapString[i] == COLLECTIBLE)
                copy_sprite_in_image(spriteTabPtr[RESSOURCE_1], map, 0 + line, 0 + height);
            line += spriteTabPtr[1].width;
            i++;
        }
    	height += spriteTabPtr[1].height;
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
