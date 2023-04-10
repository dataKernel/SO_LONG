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

    sprite.path = path;
    sprite.imgPtr = mlx_xpm_file_to_image(mlxPtr, path, &sprite.width, &sprite.height);
    sprite.addr = mlx_get_data_addr(sprite.imgPtr, &sprite.bpp, &sprite.lineLength, &sprite.endian);

    return(sprite);
}
