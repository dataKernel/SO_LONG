#ifndef MAP_H
# define MAP_H

# include <stdbool.h>

bool    check_map_has_PER(char *);
bool    check_map_is_rectangular(char *);
bool    check_map_is_walled(char *);
bool    check_player_is_close_exit(char *, int);
bool    check_map_has_path(char *);

#endif
