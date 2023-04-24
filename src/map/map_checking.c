#include "../../include/map_checking.h"
#include "../../include/map_checking_utils.h"

bool    check_map_has_PER(char *str)
{
    int     i;
	int 	p;
	int 	e;
	int 	c;

    i = 0;
	p = 0;
	e = 0;
	c = 0;
    while(str[i])
    {
        if(str[i] == PLAYER)
            p++;
        else if(str[i] == EXIT)
            e++;
        else if(str[i] == COLLECTIBLE)
            c++;
        i++;
    }
	if(p != 1 || e != 1)
		return(false);
	else if(c < 1)
		return(false);
    return(true);
}

bool    check_map_is_rectangular(char *str)
{
    int     firstLine;
    int     i;
    int     j;

    i = 0;
    //toto
    j = 0;
    firstLine = 0;
    while(str[firstLine] != '\n')
        firstLine++;
    i = firstLine + 1;
    while(str[i])
    {
        if(str[i] == '\n')
        {
            if(j != firstLine)
            {
                return(false);
            }
            j = 0;
        }
        j++;
        i++;
    }
    return(true);
}


bool    check_map_is_walled(char *str, int width, int height)
{
    int     last_posi;
    int     i;

    i = 0;
    while(i < width)
    {
        if(str[i] != WALL)
            return(false);
        i++;
    }
    i = ((width + 1) * height) - 2;
    last_posi = i;
    while(i > (last_posi - (width - 1)))
    {
        if(str[i] != WALL)
            return(false);
        i--;
    }
    return(true);
}

bool	check_player_is_close_exit(char *str, int widthLine)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if(str[i] == EXIT)
		{
			if(str[i + 1] != PLAYER &&
			str[i - 1] != PLAYER &&
			str[i - widthLine] != PLAYER &&
			str[i + widthLine] != PLAYER)
			return(false);
		}
		i++;
	}
	return(true);
}

bool	check_map_has_path(char *str)
{
	bool	check;
	int		widthLine;
	int		i;

	widthLine = check_width_line(str);
	check = true;
    while(check)
    {
        i = 0;
        check = false;
        while(str[i])
    	{
    		if(str[i] == PLAYER)
    		{
    			check = check_position_libre(str, i + 1) || check;
                check = check_position_libre(str, i - 1) || check;
                check = check_position_libre(str, i - widthLine) || check;
                check = check_position_libre(str, i + widthLine) || check;
    		}
    		i++;
    	}
    }
	return(check_player_is_close_exit(str, widthLine));
}
