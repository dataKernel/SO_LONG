#include <stdio.h>
#include "include/image.h"

/*
unsigned int 	ft_pixel_get(t_imgData sprite, int x, int y)
{
	char 	*dst = sprite.addr + (y *sprite.line_length + x * (sprite.bits_per_pixel / 8));
	return *(unsigned int *)dst;
}

void 	ft_pixel_put(t_imgData *imgData, int x, int y, int color)
{
	char 	*dst;

	dst = imgData->addr + (y * imgData->line_length + x * (imgData->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

int     main(void)
{
	t_win 	window;
	t_img 	image;

	window = create_window(1400, 700, "solong.exe");
	image = create_image(window.width, window.height, window.mlxPtr);
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, image.imgPtr, 0, 0);
	mlx_loop(window.mlxPtr);
	return(0);
}
