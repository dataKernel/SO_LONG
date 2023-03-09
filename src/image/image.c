#include <stdlib.h>
#include <stdio.h>
#include "../../include/image.h"
#include "../../include/image_utils.h"


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

void    load_path_sprite(char **arraySpritePath)
{
    arraySpritePath[0] = SPRITE_1;
    arraySpritePath[1] = SPRITE_2;
    arraySpritePath[2] = SPRITE_3;
    arraySpritePath[3] = SPRITE_4;
    arraySpritePath[4] = SPRITE_5;
    arraySpritePath[5] = SPRITE_6;
    arraySpritePath[6] = SPRITE_7;
    arraySpritePath[7] = SPRITE_8;
    arraySpritePath[8] = SPRITE_9;
}

void    load_sprite(void *mlxPtr)
{
    t_img   sprite[9];
    t_img   *ptr;
    char    *spritePath[9];
    int     i;

    i = 0;
    load_path_sprite(spritePath);
    while(i < 9)
    {
        sprite[i] = create_sprite(spritePath[i], mlxPtr);
        i++;
    }

    printf("elem char width : %i", sprite[1].width);
    //ptr = (t_img *)malloc(sizeof(ptr) * 9);

}
