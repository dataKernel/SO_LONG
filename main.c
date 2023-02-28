#include <stdio.h>
#include "include/image.h"

int     main(void)
{
	t_win 	window;
	t_img 	sprite;

	window = create_window(1400, 700, "solong.exe");
	sprite = create_sprite("assets/sprites/ground_1.xpm", window.mlxPtr);
	printf("width --> %i", sprite.width);
	printf("height --> %i", sprite.height);


	return(0);
}
