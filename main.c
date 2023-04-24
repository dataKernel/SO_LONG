#include "include/init.h"
#include <stdio.h>

int     main(void)
{
	t_gameState 	game;
	char 			*testMapString;
	char 			*mapString;
	
	srand(time(NULL));
	testMapString = read_map("assets/maps/map.ber");
	mapString = read_map("assets/maps/map.ber");
	if(!load_checking(&game, testMapString))
		return(-1);
	free(testMapString);
	printf("PROG PASSED THE MAP TEST (OK)\n");
	init_prog(&game, mapString);
	load_prog_on_win(&game);
	mlx_key_hook(game.window.winPtr, hook_character, &game);
	mlx_loop(game.window.mlxPtr);
	
	mlx_destroy_image(game.window.mlxPtr, game.mapImg.imgPtr);
	mlx_destroy_image(game.window.mlxPtr, game.collectibleSprite[0].imgPtr);
	mlx_destroy_image(game.window.mlxPtr, game.collectibleSprite[1].imgPtr);
	return(0);
}