#include "../include/init.h"
#include <stdio.h>

void    init_prog(t_gameState *game, char *mapString)
{
    t_char          character;
    t_win           window;

    window = create_window(mapString, "so_long.exe");
    character = load_character(window, mapString, CHAR_DOWN_1_PATH);    
    character.movesNbr = 0;
    character.collectibles = 0;
    game->window = window;
    game->mapImg = load_map(mapString, window);
    game->map = generate_matrix_map(mapString);
    game->character = character;
    game->collectibleSprite[0] = create_sprite(COLLECTIBLE_HP_PATH, window.mlxPtr);
    game->collectibleSprite[1] = create_sprite(COLLECTIBLE_MANA_PATH, window.mlxPtr);
}

bool    load_checking_test_map(t_gameState *game, char *mapString)
{
    bool    check;
    
    if(!check_map_has_PER(mapString))
    {
        printf("ERROR: the map has PER error...");
        return(false);
    }
    if(!check_map_is_rectangular(mapString))
    {
        printf("ERROR: the map is not rectangular...");
        return(false);
    }
    if(!check_map_is_walled(mapString, game->map.width, game->map.height))
    {
        printf("ERROR: the map is not walled...");
        return(false);
    }
    if(!check_map_has_path(mapString))
    {
        printf("ERROR: the map has not valid path...");
        return(false);
    }
    return(true);
}

bool    load_checking_ext()
{
    return(true);
}

void    load_prog_on_win(t_gameState *game)
{
    void    *mlxPtr;
    void    *winPtr;
    void    *imgPtr;
    int     x;
    int     y;
    
    mlxPtr = game->window.mlxPtr;
    winPtr = game->window.winPtr;
    imgPtr = game->mapImg.imgPtr;
    mlx_put_image_to_window(mlxPtr, winPtr, imgPtr, 0, 0);
    imgPtr = game->character.sprite.imgPtr;
    x = game->character.posiX * 40;
    y = game->character.posiY * 40 + 42;
    mlx_put_image_to_window(mlxPtr, winPtr, imgPtr, x, y);
    put_collectible_on_map(game);
}

