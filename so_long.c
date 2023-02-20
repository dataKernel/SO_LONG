#include <stdio.h>
#include "map_utils.h"
#include "map.h"

/*
XXXXX\n
XPPPX\n
XPPPX\n
XPPEX\n
*/

int     main(void)
{
	char 	*str;

	str = read_map("map.ber");
	printf("%s", str);
	printf("%s", check_map_is_walled(str) ? "true" : "false");
	return(0);
}
