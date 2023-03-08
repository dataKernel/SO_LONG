#ifndef IMAGE_H
# define IMAGE_H

# define 

# define SPRITE_GROUND_1 "../../assets/sprites/ground_1.xpm"
# define SPRITE_GROUND_2 "../../assets/sprites/ground_2.xpm"

# define

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

#endif
