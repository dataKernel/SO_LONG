#ifndef CHARACTER_H
# define CHARACTER_H

# include "image.h"

typedef struct      s_character
{
    t_img   sprite;
    int     posiX;
    int     posiY;
}t_char;

t_char      load_character(t_win window, char *mapString, char *spritePath);
int         get_position_character(char *mapString);

#endif
