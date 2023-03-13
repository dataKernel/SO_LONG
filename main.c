#include <stdio.h>
#include "include/map_checking_utils.h"
#include "include/image.h"
#include "include/image_utils.h"


int     main(void)
{
	t_win 	window;

	window = create_window(405, 490, "solong.exe");

	//checking the ptr related to win
	printf("ptr mlx --> %p\n", window.mlxPtr);
	//checking the width and height
	printf("w:%i_____h:%i\n", window.width, window.height);

	//generate_map("assets/maps/map.ber");
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
	//mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);
	//mlx_loop(window.mlxPtr);
	return(0);
}
