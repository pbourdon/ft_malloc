#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// write into the shell : limit stacksize 1 
int		main()
{
	int		index;
	char	*str;
	int		index2;

	index2 = 0;
	index = 0;
	while (index < 8100)
	{
		str = malloc(42 * index + 1);
		index++;
	}
	return (0);
}
