#include "../include/init.h"
#include <stdio.h>

t_gameState     init_prog()
{
    t_gameState     game;     
    t_char          character;
    t_win           window;
    char            *mapString;
    
    srand(time(NULL));
    mapString = read_map("assets/maps/map.ber");
    window = create_window(mapString, "so_long.exe");
    character = load_character(window, mapString, CHAR_DOWN_1_PATH);    
    character.movesNbr = 0;
    character.collectibles = 0;
    game.window = window;
    game.mapImg = load_map(mapString, window);
    game.map = generate_matrix_map(mapString);
    game.character = character;
    return(game);
}