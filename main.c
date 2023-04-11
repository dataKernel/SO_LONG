#include <stdio.h>

#include "include/map_checking_utils.h"
#include "include/collectible.h"
#include "include/image_utils.h"
#include "include/character.h"
#include "include/events.h"
#include "include/image.h"
#include "include/map.h"

int     main(void)
{
	t_events 		events;
	t_char 			character;
	t_win 			window;
	t_img 			mapImg;
	t_map 			map;
	char 			*mapString;
	int 			winWidth;
	int 			winHeight;
	int 			posCharX;
	int 			posCharY;
	//init seed
	srand(time(NULL));
	//map generation et windows size
	mapString = read_map("assets/maps/map.ber");
	winWidth = check_width_line(mapString) * 40;
	winHeight = check_height_column(mapString) * 40 + 42;
	window = create_window(winWidth, winHeight, "so_long.exe");

	mapImg = load_map(mapString, window);
	character = load_character(window, mapString, "assets/sprites/character_down_1.xpm");
	posCharX = character.posiX * 40;
	posCharY = character.posiY * 40 + 42;
	//push des elems dans la fenetre
	mlx_put_image_to_window(window.mlxPtr, window.winPtr, character.sprite.imgPtr, posCharX, posCharY);
	map = generate_matrix_map(mapString);
	
	mlx_key_hook(window.winPtr, check_key, &events);
	mlx_loop(window.mlxPtr);
	return(0);
}