#ifndef IMAGE_H
# define IMAGE_H

# define SPRITE_1 "assets/sprites/character.xpm"
# define SPRITE_2 "assets/sprites/ground_1.xpm"
# define SPRITE_3 "assets/sprites/ground_2.xpm"
# define SPRITE_4 "assets/sprites/wall_top.xpm"
# define SPRITE_5 "assets/sprites/wall_tree_1.xpm"
# define SPRITE_6 "assets/sprites/wall_tree_2.xpm"
# define SPRITE_7 "assets/sprites/wall_tree_3.xpm"
# define SPRITE_8 "assets/sprites/wall_tree_4.xpm"
# define SPRITE_9 "assets/sprites/wall_tree_5.xpm"

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

    int     lineLength;
    int     endian;
    int     bpp;
    int     width;
    int     height;

}t_img;

t_win   create_window(int w, int h, char *title);
t_img   create_image(int w, int h, void *mlxPtr);
t_img   create_sprite(char *path, void *mlxPtr);

void    load_sprite(void *mlxPtr);

#endif
