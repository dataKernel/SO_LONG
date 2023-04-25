#ifndef INIT_H
# define INIT_H

# include "../include/map_checking_utils.h"
# include "../include/map_checking.h"
# include "../include/collectible.h"
# include "../include/image_utils.h"
# include "../include/character.h"
# include "../include/events.h"
# include "../include/map.h"

bool    load_checking_test_map(t_gameState *game, char *mapString);
bool    load_checking_ext();
void    init_prog(t_gameState *game, char *mapString);
void    load_prog_on_win(t_gameState *game);

#endif