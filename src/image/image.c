#include <stdlib.h>
#include <stdio.h>
#include "../../include/image_utils.h"
#include "../../include/image.h"


t_win   create_window(int w, int h, char *title)
{
    t_win   window;

    window.width = w;
    window.height = h;
    window.title = title;
    window.mlxPtr = mlx_init();
    window.winPtr = mlx_new_window(window.mlxPtr, w, h, title);

    return(window);
}

t_img   create_image(int w, int h, void *mlxPtr)
{
    t_img   image;

    image.width = w;
    image.height = h;
    image.imgPtr = mlx_new_image(mlxPtr, w, h);
    image.addr = mlx_get_data_addr(image.imgPtr, &image.bpp, &image.lineLength, &image.endian);

    return(image);
}

t_img   create_sprite(char *path, void *mlxPtr)
{
    t_img   sprite;

    sprite.imgPtr = mlx_xpm_file_to_image(mlxPtr, path, &sprite.width, &sprite.height);
    sprite.addr = mlx_get_data_addr(sprite.imgPtr, &sprite.bpp, &sprite.lineLength, &sprite.endian);

    return(sprite);
}

char    *rm_backslash_mapstring(char *map)
{
    char    *dst;
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
    dst = (char *)malloc(sizeof(char) * (sizeMap + 1));
    if(dst == NULL)
        printf("ERROR_MALLOC\n");
    i = 0;
    j = 0;
    while(map[i])
    {
        printf("%c\n", dst[j]);
        if(map[i] != '\n')
        {
            dst[j] = map[i];
            j++;
        }
        i++;
    }
    return(dst);
}
