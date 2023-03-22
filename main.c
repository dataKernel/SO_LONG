#include <stdio.h>

#include "include/map_checking_utils.h"
#include "include/image_utils.h"
#include "include/character.h"
#include "include/image.h"
#include "include/map.h"

int     main(void)
{
	t_char 	character;
	t_win 	window;
	t_img 	map;
	char 	*mapString;
	int 	winHeight;
	int 	winWidth;

	//init seed
	srand(time(NULL));
	//map generation et windows size
	mapString = read_map("assets/maps/map.ber");
	winWidth = check_width_line(mapString) * 40;
	winHeight = (check_height_column(mapString) - 1) * 40 + 82;
	window = create_window(winWidth, winHeight, "so_long.exe");
	map = generate_map(mapString, window);
	character = load_character(window, mapsString);
	//push du perso
	//push des elems dans la fenetre
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, map.imgPtr, 0, 0);

	mlx_loop(window.mlxPtr);
	return(0);
}
