#include <stdio.h>

#include "../../include/image_utils.h"
#include "../../include/map.h"
#include "../../include/map_checking_utils.h"

t_img    generate_map(char *pathMap, t_win window)
{
    char    *mapString;
    t_img   *spriteTabPtr;
    t_img   map;
    int     widthMap;
    int     heightMap;

    mapString = read_map(pathMap);
    map = create_image(window.width, window.height, window.mlxPtr);
    spriteTabPtr = load_sprite(window.mlxPtr);
    copy_sprite_in_image(map, spriteTabPtr[3], 0, 0);

    return(map);
}
