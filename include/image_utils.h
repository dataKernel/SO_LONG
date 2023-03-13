#ifndef IMAGE_UTILS_H
# define IMAGE_UTILS_H

# include "image.h"

unsigned int 	ft_pixel_get(t_img image, int x, int y);
t_img           *load_sprite(void *mlxPtr);
void            ft_pixel_put(t_img image, int x, int y, int color);
void            copy_sprite_in_image(t_img sprite, t_img image, int x, int y);
void            load_path_sprite(char **arraySpritePath);

#endif
