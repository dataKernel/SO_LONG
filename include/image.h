#ifndef IMAGE_H
# define IMAGE_H

# define CHAR_1 "assets/sprites/character.xpm"
# define GROUND_1 "assets/sprites/ground_1.xpm"
# define GROUND_2 "assets/sprites/ground_2.xpm"
# define WALL_TOP "assets/sprites/wall_top.xpm"
# define WALL_TREE_1 "assets/sprites/wall_tree_1.xpm"
# define WALL_TREE_2 "assets/sprites/wall_tree_2.xpm"
# define WALL_TREE_3 "assets/sprites/wall_tree_3.xpm"
# define WALL_TREE_4 "assets/sprites/wall_tree_4.xpm"
# define WALL_TREE_5 "assets/sprites/wall_tree_5.xpm"

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
