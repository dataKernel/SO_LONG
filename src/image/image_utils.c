#include "../../include/image.h"
#include "../../include/image_utils.h"
#include <stdio.h>

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

void 			copy_sprite_in_image(t_img sprite, t_img image, int x, int y)
{
	int 	line;
	int 	pixel;

	line = y;
	while(line < sprite.height)
	{
		printf("line --> %i\n", line);
		printf("pixel --> %i\n", pixel);
		pixel = x;
		while(pixel < sprite.width)
		{
			ft_pixel_put(image, pixel, line, ft_pixel_get(sprite, pixel, line));
			pixel++;
		}
		line++;
	}
}


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
