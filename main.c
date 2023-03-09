#include <stdio.h>
#include "include/image.h"
#include "include/image_utils.h"


int     main(void)
{
	t_win 	window;
	t_img 	map;
	t_img 	*tabSprite;

	window = create_window(405, 490, "solong.exe");
	tabSprite = load_sprite(window.mlxPtr);
	printf("%s", tabSprite[1].path);
	printf("%s", tabSprite[0].path);
	printf("\n\n\n");
	printf("elem --> %s, width: %i", tabSprite[7].path, tabSprite[7].width);
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
