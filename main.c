#include <stdio.h>
#include "include/image.h"
#include "include/image_utils.h"

int     main(void)
{
	t_win 	window;
	t_img 	map;
	t_img 	sprite;

	window = create_window(1400, 700, "solong.exe");
	map = create_image(window.width, window.height, window.mlxPtr);
	sprite = create_sprite("assets/sprites/character.xpm", window.mlxPtr);
	//we copy the sprite inside the map
	copy_sprite_in_image(sprite, map, 0, 0);
	//pushing the image map in the window
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);
	mlx_loop(window.mlxPtr);

	return(0);
}
