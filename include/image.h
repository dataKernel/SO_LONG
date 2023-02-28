#ifndef IMAGE_H
# define IMAGE_H

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

t_win   create_window(int, int, char *);
t_img   create_image(int w, int h, void *);
t_img   create_sprite(char *, void *);
void    copy_sprite_in_image(t_img, t_img, int, int);

#endif
