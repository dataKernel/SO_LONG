#include "../../include/image.h"
#include "../../include/image_utils.h"
#include <stdio.h>


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




/*
unsigned int     ft_pixel_get(t_imgData sprite, int x, int y)
{
    char     *dst = sprite.addr + (y *sprite.line_length + x * (sprite.bits_per_pixel / 8));
    return *(unsigned int *)dst;
}

void     ft_pixel_put(t_imgData *imgData, int x, int y, int color)
{
    char     *dst;

    dst = imgData->addr + (y * imgData->line_length + x * (imgData->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
*/


/*
while(ligne < sprite.height)
    {
        pixel = 0;
        while(pixel < sprite.width)
        {
            ft_pixel_put(&map, 15 + pixel, 15 + ligne, ft_pixel_get(sprite, pixel, ligne));
            pixel++;
        }
        ligne++;
    }
*/
