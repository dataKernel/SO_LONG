#ifndef IMAGE_H
# define IMAGE_H

# define CHAR_1 0
# define GROUND_1 1
# define GROUND_2 2
# define WALL_TOP 3
# define WALL_TREE_1 4
# define WALL_TREE_2 5
# define WALL_TREE_3 6
# define WALL_TREE_4 7
# define WALL_TREE_5 8
# define RESSOURCE_1 9
# define EXIT_1 10


# define CHAR_1_PATH "assets/sprites/character.xpm"
# define GROUND_1_PATH "assets/sprites/ground_1.xpm"
# define GROUND_2_PATH "assets/sprites/ground_2.xpm"
# define WALL_TOP_PATH "assets/sprites/wall_top.xpm"
# define WALL_TREE_1_PATH "assets/sprites/wall_tree_1.xpm"
# define WALL_TREE_2_PATH "assets/sprites/wall_tree_2.xpm"
# define WALL_TREE_3_PATH "assets/sprites/wall_tree_3.xpm"
# define WALL_TREE_4_PATH "assets/sprites/wall_tree_4.xpm"
# define WALL_TREE_5_PATH "assets/sprites/wall_tree_5.xpm"
# define RESSOURCE_1_PATH "assets/sprites/ressource.xpm"
# define EXIT_PATH "assets/sprites/exit.xpm"

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

#endif
