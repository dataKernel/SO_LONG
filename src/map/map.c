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
    //test d'afficher le path d'un sprite
    printf("path-->%s\n", spriteTabPtr[0].path);
    printf("path-->%s\n", spriteTabPtr[1].path);
    printf("path-->%s\n", spriteTabPtr[2].path);
    printf("path-->%s\n", spriteTabPtr[3].path);
    return(map);
}
