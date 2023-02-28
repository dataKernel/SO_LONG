#include "../../include/image.h"
#include "../../include/image_utils.h"

unsigned int 	ft_pixel_get(t_img image, int x, int y)
{
	char 	*dst = image.addr + (y *image.lineLength + x * (image.bpp / 8));
	return *(unsigned int *)dst;
}

void            ft_pixel_put(t_img image, int x, int y, int color)
{
	char 	*dst;

	dst = image.addr + (y * image.lineLength + x * (image.bpp / 8));
	*(unsigned int*)dst = color;
}

//void    copy_sprite_in_image(t_img, t_img, int, int);
