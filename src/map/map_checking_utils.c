#include "../../include/map_checking_utils.h"
#include "../../include/image_utils.h"

char    *read_map(char *path)
{
    char    tmp;
    char    *map;
    int     fd;
    int     size;
    int     totalMapSize;

    totalMapSize = 0;
    size = 1;
    fd = open(path, O_RDONLY);
    while(size == 1)
    {
        totalMapSize++;
        size = read(fd, &tmp, 1);
    }
    close(fd);
    fd = open(path, O_RDONLY);
    map = malloc(sizeof(char) * (totalMapSize + 2));
    read(fd, map, totalMapSize);
    close(fd);
    map[totalMapSize +1] = '\0';
    map[totalMapSize] = '\n';
    return(map);
}

bool check_position_libre(char *str, int position)
{
  if (str[position] == SPACE || str[position] == COLLECTIBLE)
  {
    str[position] = PLAYER;
    return true;
  }
  return false;
}


int		check_width_line(char *str)
{
	int		width;

	width = 0;
	while(str[width])
	{
		if(str[width] == '\n')
		{
			width += 1;
			break;
		}
		width++;
	}
	return(width);
}

int     check_height_column(char *str)
{
    int     height;
    int     i;

    i = 0;
    height = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            height++;
        i++;
    }
    return(height);
}
