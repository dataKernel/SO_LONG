#include <stdio.h>
#include "include/image.h"
#include "include/image_utils.h"




int     main(void)
{
	t_win 	window;
	t_img 	map;
	t_img 	spriteGround1;
	t_img 	spriteChar;

	int 	line;
	int 	height;

	height = 0;
	window = create_window(800, 800, "solong.exe");
	map = create_image(window.width, window.height, window.mlxPtr);
	spriteGround1 = create_sprite("assets/sprites/ground_1.xpm", window.mlxPtr);
	spriteChar = create_sprite("assets/sprites/character.xpm", window.mlxPtr);
	//we copy the spriteGround inside the map
	while(height < map.height)
	{
		line = 0;
		while(line < map.width)
		{
			copy_sprite_in_image(spriteGround1, map, 0 + line, 0 + height);
			line += spriteGround1.width;
		}
		height += spriteGround1.height;
	}
	//pushing the image map in the window
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, spriteChar.imgPtr, 360, 160);
	mlx_loop(window.mlxPtr);

	return(0);
}
