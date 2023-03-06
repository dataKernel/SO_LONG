#include <stdio.h>
#include "include/image.h"
#include "include/image_utils.h"




int     main(void)
{
	t_win 	window;
	t_img 	map;
	t_img 	spriteGround1;
	t_img 	spriteChar;
	t_img 	spriteWallTop;
	t_img 	spriteWallTree1;
	t_img 	spriteWallTree2;
	t_img 	spriteWallRock1;

	int 	line;
	int 	height;

	height = 0;
	window = create_window(405, 510, "solong.exe");
	map = create_image(window.width, window.height, window.mlxPtr);
	spriteGround1 = create_sprite("assets/sprites/ground_1.xpm", window.mlxPtr);
	spriteChar = create_sprite("assets/sprites/character.xpm", window.mlxPtr);
	spriteWallTop = create_sprite("assets/sprites/wall_top.xpm", window.mlxPtr);
	spriteWallTree1 = create_sprite("assets/sprites/wall_tree_1.xpm", window.mlxPtr);
	spriteWallTree2 = create_sprite("assets/sprites/wall_tree_2.xpm", window.mlxPtr);
	spriteWallRock1 = create_sprite("assets/sprites/wall_rock_1.xpm", window.mlxPtr);

	copy_sprite_in_image(spriteWallTop, map, 0, 0);
	copy_sprite_in_image(spriteWallTop, map, 80, 0);
	copy_sprite_in_image(spriteWallTop, map, 160, 0);
	copy_sprite_in_image(spriteWallTop, map, 240, 0);
	copy_sprite_in_image(spriteWallTop, map, 320, 0);

	copy_sprite_in_image(spriteWallRock1, map, 0,spriteWallTop.height);
	copy_sprite_in_image(spriteGround1, map, 80,spriteWallTop.height);
	copy_sprite_in_image(spriteGround1, map, 160,spriteWallTop.height);
	copy_sprite_in_image(spriteWallTree1, map, 240,spriteWallTop.height);
	copy_sprite_in_image(spriteGround1, map, 320,spriteWallTop.height);

	copy_sprite_in_image(spriteWallTree2, map, 0,spriteWallTop.height + 80);
	copy_sprite_in_image(spriteGround1, map, 80,spriteWallTop.height + 80);
	copy_sprite_in_image(spriteGround1, map, 160,spriteWallTop.height + 80);
	copy_sprite_in_image(spriteGround1, map, 240,spriteWallTop.height + 80);
	copy_sprite_in_image(spriteGround1, map, 320,spriteWallTop.height + 80);

	copy_sprite_in_image(spriteGround1, map, 0,spriteWallTop.height + 80 *2);
	copy_sprite_in_image(spriteGround1, map, 80,spriteWallTop.height + 80 *2);
	copy_sprite_in_image(spriteGround1, map, 160,spriteWallTop.height + 80 *2);
	copy_sprite_in_image(spriteGround1, map, 240,spriteWallTop.height + 80 *2);
	copy_sprite_in_image(spriteGround1, map, 320,spriteWallTop.height + 80 *2);


	//we copy the spriteGround inside the map
	/*while(height < map.height)
	{
		line = 0;
		while(line < map.width)
		{
			copy_sprite_in_image(spriteGround1, map, 0 + line, 0 + height);
			line += spriteGround1.width;
		}
		height += spriteGround1.height;
	}*/
	//pushing the image map in the window
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, spriteChar.imgPtr, 200, 250);
	mlx_loop(window.mlxPtr);

	return(0);
}
