#include <stdlib.h>
#include "../../include/image.h"
#include "../../include/image_utils.h"

unsigned int 	ft_pixel_get(t_img image, int x, int y)
{
	char 	*dst = image.addr + (y *image.lineLength + (x * (image.bpp / 8)));
	return *(unsigned int *)dst;
}

void 	ft_pixel_put(t_img image, int x, int y, int color)
{
	char 	*dst;

	dst = image.addr + (y * image.lineLength + (x * (image.bpp / 8)));
	*(unsigned int*)dst = color;
}

void 	copy_sprite_in_image(t_img sprite, t_img image, int x, int y)
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
    arraySpritePath[0] = GROUND_1_PATH;
    arraySpritePath[1] = GROUND_2_PATH;
    arraySpritePath[2] = WALL_TOP_PATH;
    arraySpritePath[3] = WALL_TREE_1_PATH;
	arraySpritePath[4] = WALL_TREE_2_PATH;
    arraySpritePath[5] = WALL_TREE_3_PATH;
    arraySpritePath[6] = WALL_TREE_4_PATH;
    arraySpritePath[7] = WALL_TREE_5_PATH;
	arraySpritePath[8] = RESSOURCE_1_PATH;
	arraySpritePath[9] = RESSOURCE_2_PATH;
	arraySpritePath[10] = EXIT_PATH;
	arraySpritePath[11] = CHAR_DOWN_1_PATH;
	arraySpritePath[12] = CHAR_DOWN_2_PATH;
	arraySpritePath[13] = CHAR_DOWN_3_PATH;
}

t_img   *load_sprite(void *mlxPtr)
{
    t_img   *spriteTab;
    char    *spritePathTab[14];
    int     i;

    i = 0;
    spriteTab = (t_img *)malloc(sizeof(t_img) * 14);
    load_path_sprite(spritePathTab);
    while(i < 14)
    {
        spriteTab[i] = create_sprite(spritePathTab[i], mlxPtr);
        spriteTab[i].path = spritePathTab[i];
        i++;
    }
    return(spriteTab);
}
