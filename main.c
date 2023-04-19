#include "include/init.h"
#include <stdio.h>

int     main(void)
{
	t_gameState 	game;
	
	srand(time(NULL));
	init_prog(&game);
	load_prog_on_win(&game);
	mlx_key_hook(game.window.winPtr, hook_character, &game);
	mlx_loop(game.window.mlxPtr);
	return(0);
}