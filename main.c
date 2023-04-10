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
	winHeight = (check_height_column(mapString) - 1) * 40 + 82;
	window = create_window(winWidth, winHeight, "so_long.exe");
	mapImg = load_map(mapString, window);
	map = generate_matrix_map(mapString);
	//push des elems dans la fenetre
	mlx_loop(window.mlxPtr);
	return(0);
}
