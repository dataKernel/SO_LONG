#include <stdio.h>

#include "include/map_checking_utils.h"
#include "include/image.h"
#include "include/image_utils.h"
#include "include/map.h"

int     main(void)
{
	t_win 	window;
	t_img 	character;
	t_img 	map;
	char 	*mapString;
	int 	winHeight;
	int 	winWidth;

	mapString = read_map("assets/maps/map.ber");
	winWidth = check_width_line(mapString) * 40;
	winHeight = (check_height_column(mapString) - 1) * 40 + 82;
	window = create_window(winWidth, winHeight, "so_long.exe");
	map = generate_map(mapString, window);
	character = create_sprite(CHAR_1_PATH, window.mlxPtr);
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);
	//on push le personnage sur la posi de map
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, character.imgPtr, )
	mlx_loop(window.mlxPtr);
	return(0);
}
