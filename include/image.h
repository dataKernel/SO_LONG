#ifndef IMAGE_H
# define IMAGE_H

# define GROUND_1 0
# define GROUND_2 1
# define WALL_TOP 2
# define WALL_TREE_1 3
# define WALL_TREE_2 4
# define WALL_TREE_3 5
# define WALL_TREE_4 6
# define WALL_TREE_5 7

# define COLLECTIBLE_HP 8
# define COLLECTIBLE_MANA 9
# define EXIT_1 10

# define CHAR_DOWN_1 11
# define CHAR_DOWN_2 12
# define CHAR_DOWN_3 13

# define CHAR_TOP_1 14
# define CHAR_TOP_2 15
# define CHAR_TOP_3 16
# define CHAR_RIGHT_1 17
# define CHAR_RIGHT_2 18
# define CHAR_RIGHT_3 19
# define CHAR_LEFT_1 20
# define CHAR_LEFT_2 21
# define CHAR_LEFT_3 22

# define GROUND_1_PATH "assets/sprites/ground_1.xpm"
# define GROUND_2_PATH "assets/sprites/ground_2.xpm"
# define WALL_TOP_PATH "assets/sprites/wall_top.xpm"
# define WALL_TREE_1_PATH "assets/sprites/wall_tree_1.xpm"
# define WALL_TREE_2_PATH "assets/sprites/wall_tree_2.xpm"
# define WALL_TREE_3_PATH "assets/sprites/wall_tree_3.xpm"
# define WALL_TREE_4_PATH "assets/sprites/wall_tree_4.xpm"
# define WALL_TREE_5_PATH "assets/sprites/wall_tree_5.xpm"

# define COLLECTIBLE_HP_PATH "assets/sprites/ressource_1.xpm"
# define COLLECTIBLE_MANA_PATH "assets/sprites/ressource_2.xpm"
# define EXIT_PATH "assets/sprites/exit.xpm"

# define CHAR_DOWN_1_PATH "assets/sprites/character_down_1.xpm"
# define CHAR_DOWN_2_PATH "assets/sprites/character_down_2.xpm"
# define CHAR_DOWN_3_PATH "assets/sprites/character_down_3.xpm"
# define CHAR_TOP_1_PATH "assets/sprites/character_top_1.xpm"
# define CHAR_TOP_2_PATH "assets/sprites/character_top_2.xpm"
# define CHAR_TOP_3_PATH "assets/sprites/character_top_3.xpm"
# define CHAR_RIGHT_1_PATH "assets/sprites/character_right_1.xpm"
# define CHAR_RIGHT_2_PATH "assets/sprites/character_right_2.xpm"
# define CHAR_RIGHT_3_PATH "assets/sprites/character_right_3.xpm"
# define CHAR_LEFT_1_PATH "assets/sprites/character_left_1.xpm"
# define CHAR_LEFT_2_PATH "assets/sprites/character_left_2.xpm"
# define CHAR_LEFT_3_PATH "assets/sprites/character_left_3.xpm"

# include "../libx_opengl/mlx.h"

typedef struct  s_win
{
    void    *mlxPtr;
    void    *winPtr;

    char    *title;
    int     width;
    int     height;
}t_win;

typedef struct  s_img
{
    void    *imgPtr;
    void    *addr;

    char    *path;
    int     lineLength;
    int     endian;
    int     bpp;
    int     width;
    int     height;
}t_img;

t_win   create_window(int w, int h, char *title);
t_img   create_image(int w, int h, void *mlxPtr);
t_img   create_sprite(char *path, void *mlxPtr);
void    rm_backslash_mapstring(char *map, char **dst);

#endif
