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

	image.width = 12;
	window.width = 12;


	return(0);
}
