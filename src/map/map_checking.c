#include "include/map_checking.h"
#include "include/map_checking_utils.h"

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
    j = 0;
    firstLine = 0;
    //on compte le nombre de char par ligne
    while(str[firstLine] != '\n')
        firstLine++;
    i = firstLine + 1; //on va directement a la 2eme ligne
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


bool    check_map_is_walled(char *str)
{
    int     last_posi;
    int     width;
    int     height;
    int     i;
	//on peut créer une fonction avec str qui va check la largeur et hauteur
    //on check la largeur et hauteur de la map
    width = 0;
    height = 0;
    i = 0;
    while(str[width] != '\n')
        width++;
    while(str[i])
    {
        if(str[i] == '\n')
            height++;
        i++;
    }
    //on verifie que la 1ere et derniere ligne sont walled
    i = 0;
    while(i < width)
    {
        if(str[i] != WALL)
            return(false);
        i++;
    }
    i = ((width + 1) * height) - 2; // on va a la derniere posi de la map en exculant le \n
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
