#include <stdlib.h>
#include "../../include/image.h"
#include "../../include/image_utils.h"

unsigned int 	ft_pixel_get(t_img image, int x, int y)
{
	char 	*dst = image.addr + (y *image.lineLength + (x * (image.bpp / 8)));
	return *(unsigned int *)dst;
}

void            ft_pixel_put(t_img image, int x, int y, int color)
{
	char 	*dst;

	dst = image.addr + (y * image.lineLength + (x * (image.bpp / 8)));
	*(unsigned int*)dst = color;
}

void 			copy_sprite_in_image(t_img sprite, t_img image, int x, int y)
{
	int 	line;
	int 	pixel;

	line = 0;
	while(line <= sprite.height)
	{
		pixel = 0;
		while(pixel <= sprite.width)
		{
			ft_pixel_put(image, x + pixel, y + line, ft_pixel_get(sprite, pixel, line));
			pixel++;
		}
		line++;
	}
}

void    load_path_sprite(char **arraySpritePath)
{
    arraySpritePath[0] = CHAR_1;
    arraySpritePath[1] = GROUND_1;
    arraySpritePath[2] = GROUND_2;
    arraySpritePath[3] = WALL_TOP;
    arraySpritePath[4] = WALL_TREE_1;
	arraySpritePath[5] = WALL_TREE_2;
    arraySpritePath[6] = WALL_TREE_3;
    arraySpritePath[7] = WALL_TREE_4;
    arraySpritePath[8] = WALL_TREE_5;
}

t_img   *load_sprite(void *mlxPtr)
{
    t_img   spriteTab[9];
    t_img   *ptr;
    char    *spritePathTab[9];
    int     i;

    i = 0;
    ptr = (t_img *)malloc(sizeof(ptr) * 9);
    load_path_sprite(spritePathTab);
    while(i < 9)
    {
        spriteTab[i] = create_sprite(spritePathTab[i], mlxPtr);
        spriteTab[i].path = spritePathTab[i];
        ptr[i] = spriteTab[i];
        i++;
    }
    return(ptr);
}
