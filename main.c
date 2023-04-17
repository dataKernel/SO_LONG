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
	//init seed
	srand(time(NULL));
	//map generation et windows size
	mapString = read_map("assets/maps/map.ber");
	winWidth = check_width_line(mapString) * 40;
	winHeight = check_height_column(mapString) * 40 + 42;
	window = create_window(winWidth, winHeight, "so_long.exe");
	mapImg = load_map(mapString, window);
	character = load_character(window , mapString, CHAR_DOWN_1_PATH);
	character.movesNbr = 0; //setup the move 
	character.collectibles = 0;
	map = generate_matrix_map(mapString);
	//debug checking collectible posi
	//set events
	events.window = window;
	events.mapImg = mapImg;
	events.map = map;
	events.character = character;
	events.collectibleSprite[0] = create_sprite(COLLECTIBLE_HP_PATH, window.mlxPtr);
	events.collectibleSprite[1] = create_sprite(COLLECTIBLE_MANA_PATH, window.mlxPtr);
	//push hook
	put_collectible_on_map(&events);
	mlx_key_hook(window.winPtr, hook_character, &events);
	mlx_loop(window.mlxPtr);
	return(0);
}