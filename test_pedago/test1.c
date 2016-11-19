#include <stdlib.h>

int		main()
{
	int		index;
	char	*str;

	index = 0;
	while (index < 8192)
	{
		str = malloc(42 * index + 1);
		str[0] = 42;
		index++;
	}
	return (0);
}
