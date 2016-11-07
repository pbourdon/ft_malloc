#include "malloc.h"

void	*ft_malloc(size_t size)
{
	static t_dlist	*list;

	list = dlist_new(list);
	ft_putstr("\n-------------\n");
	ft_add_data_int(list, size);
	ft_add_data_int(list, 100);
	ft_display_list2(list);
	ft_putstr("--------------\n");
	// ft_choose(size, list);
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
	str = ft_malloc(sizeof(char) * 10);
	str = ft_malloc(sizeof(char) * 123);
}
