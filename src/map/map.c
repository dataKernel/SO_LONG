#include <stdio.h>

#include "../../include/image_utils.h"
#include "../../include/map.h"
#include "../../include/map_checking_utils.h"

void    generate_wall_top(t_img map, t_img *spriteTabPtr, int line)
{
    while(line < map.width)
    {
        copy_sprite_in_image(spriteTabPtr[3], map, 0 + line, 0);
        line += spriteTabPtr[3].width;
    }
}

void    generate_map_content(t_img map, t_img *spriteTabPtr, int line, int height)
{
    while(height < map.height)
    {
    	line = 0;
    	while(line < map.width)
    	{
    		copy_sprite_in_image(spriteTabPtr[1], map, 0 + line, 0 + height);
    		line += spriteTabPtr[1].width;
    	}
    	height += spriteTabPtr[1].height;
    }
}

t_img    generate_map(char *mapString, t_win window)
{
    t_img   *spriteTabPtr;
    t_img   map;
    int     widthMap;
    int     heightMap;
    int     line;
    int     height;

    line = 0;
    height = 82;
    map = create_image(window.width, window.height, window.mlxPtr);
    spriteTabPtr = load_sprite(window.mlxPtr);
    generate_wall_top(map, spriteTabPtr, line);

    free(spriteTabPtr);

    return(map);
}
