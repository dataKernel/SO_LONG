#include <stdio.h>
#include <stdbool.h>
//map legend
// X == walls
// _ == space
// P == player
// R == ressources
// E == exit

//map layout
/*
XXXXXXX\n
X__P__X\n
XR__XEX\n
XXXXXXX\n
*/

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
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
        switch(str[i])
		{
			case 'P':
				p++;
				break;
			case 'E':
				e++;
				break;
			case 'C':
				c++;
				break;
		}
        i++;
    }
	if(p != 1 && e != 1)
	{
		printf("ok");
		return(false);
	}
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
        if(str[i] != 'X')
            return(false);
        i++;
    }
    i = ((width + 1) * height) - 2; // on va a la derniere posi de la map en exculant le \n
    last_posi = i;
    while(i > (last_posi - (width - 1)))
    {
        if(str[i] != 'X')
            return(false);
        i--;
    }
    return(true);
}
int     get_index(int y, int x, int width)
{
    int     index;

    index = width * y + x;
    return(index);
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

bool	check_player_is_close_exit(char *str, int widthLine)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if(str[i] == 'E')
		{
			if(str[i + 1] != 'P' &&
			str[i - 1] != 'P' &&
			str[i - widthLine] != 'P' &&
			str[i + widthLine] != 'P')
			return(false);
		}
		i++;
	}
	return(true);
}

bool	check_map_path(char *str)
{
	bool	check;
	int		widthLine;
	int		i;

	widthLine = check_width_line(str);
	do
	{
		i = 0;
		check = false;
		while(str[i])
		{
			if(str[i] == 'P')
			{
				if(str[i + 1] == '_' || str[i + 1] == 'R')//droite
				{
					check = true;
					str[i + 1] = 'P';
				}
				if(str[i - 1] == '_' || str[i - 1] == 'R')//gauche
				{
					check = true;
					str[i - 1] = 'P';
				}
				if(str[i - widthLine] == '_' || str[i - widthLine] == 'R')//haut
				{
					check = true;
					str[i - widthLine] = 'P';
				}
				if(str[i + widthLine] == '_' || str[i] + widthLine == 'R')
				{
					check = true;
					str[i + widthLine] = 'P';
				}
			}
			i++;
		}
	printf("APRES ALTERATION-----------------------------------\n");
	for(i = 0; i < 24; i++)
		printf("[%i]-->%c\n", i, str[i]);
	}while(check);
	return(true);
}
/*
XXXXX\n
XPPPX\n
XPPPX\n
XPPEX\n
*/

int     main(void)
{
	char 	*str;

	str = "XXXX\nX0PPX\nX0E0X\nXCCCX\nXXXX\n\0";
	printf("%i", check_map_has_PER(str));
	return(0);
}
