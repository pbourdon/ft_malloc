#include <stdlib.h>

int		main()
{
	int		index;
	char	*str;

	index = 0;
	while (index < 1024)
	{
		str = malloc(1024);
		str[0] = 42;
		index++;
	}
	return (0);
}
