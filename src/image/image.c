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

t_img   create_image(int w, int h, void *mlx)
{
    t_img   image;

    image.width = w;
    image.height = h;
    image.imgPtr = mlx_new_image(mlx, w, h);
    image.addr = mlx_get_data_addr(image.imgPtr, &image.bpp, &image.lineLength, &image.endian);

    return(image);
}
