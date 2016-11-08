#include "malloc.h"

t_master	*global;

void	*ft_malloc(size_t size)
{
	if (global == NULL)
		global = dlist_new_master(global);

	/*
	char	*str;

	str = (char *)mmap(0, size + 1, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	return (str);
	*/
	return (NULL);
}

int		main(void)
{
	char	*str;
	int		index;
	long	page_size;

	index = 0;
	str = ft_malloc(10);
}
