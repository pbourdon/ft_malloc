#include "malloc.h"

t_master	*global;

void	*ft_malloc(size_t size)
{
	if (global == NULL)
		global = dlist_new_master(global);
	return (ft_choose(size, global));
}

int		main(void)
{
	char	*str;
	int		index;
	long	page_size;

	index = 0;
	str = ft_malloc(10);
}
