#include "../../include/image_utils.h"


unsigned int 	ft_pixel_get(t_imgData image, int x, int y)
{
	char 	*dst = image.addr + (y *image.line_length + x * (image.bits_per_pixel / 8));
	return *(unsigned int *)dst;
}

void            ft_pixel_put(t_imgData image, int x, int y, int color)
{
	char 	*dst;

	dst = imgage.addr + (y * imgage.line_length + x * (imgage.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
