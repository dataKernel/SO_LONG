#ifndef MAP_CHECKING_H
# define MAP_CHECKING_H

# include <stdbool.h>

bool    check_map_has_PER(char *str);
bool    check_map_is_rectangular(char *str);
bool    check_map_is_walled(char *str, int width, int height);
bool    check_player_is_close_exit(char *str, int widthLine);
bool    check_map_has_path(char *str);

#endif
