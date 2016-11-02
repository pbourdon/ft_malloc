#include "malloc.h"

void	*ft_malloc(size_t size)
{
	char	*str;

	str = (char *)mmap(0, size + 1, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	return (str);
}

int		main(void)
{
	char	*str;
	int		index;

	index = 0;
	str = ft_malloc(sizeof(char) * 10);
	while (index < 10)
	{
		str[index] = 'a';
		index++;
	}
	printf ("%s", str);
	return (0);
}
