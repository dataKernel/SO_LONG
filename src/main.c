#include <stdio.h>
#include "libx_opengl/mlx.h"
#include "utils/map_utils.h"
#include "map.h"

typedef struct 		s_imgData
{
	void 	*img;
	void 	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	width;
	int 	height;
	int 	endian;
}t_imgData;


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


int     main(void)
{
	t_imgData 		map;
	t_imgData 		sprite;

	void 			*mlx;
	void 			*window;

	//value pr parcourir le sprite
	int 	ligne;
	int 	pixel;


	mlx = mlx_init();
	if(mlx == NULL)
		return(-1); //erreur sur l'init
	window = mlx_new_window(mlx, 1400, 700, "sl.exe");
	if(window == NULL)
		return(-1); //erreur sur la window
	//creation de l'image de destination + setup w:h values
	map.width = 1400;
	map.height = 700;
	map.img = mlx_new_image(mlx, map.width, map.height);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	//creation de l'image source (sprite)
	sprite.img = mlx_xpm_file_to_image(mlx, "./sprites/character_base_1.xpm", &sprite.width, &sprite.height);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);


	ligne = 0;

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
	mlx_put_image_to_window(mlx, window, map.img, 0, 0);
	mlx_loop(mlx);
	return(0);
}
