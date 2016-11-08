#include "malloc.h"

t_dlist		*list_global;

void	*ft_malloc(size_t size)
{

	if (list_global == NULL)
		list_global = dlist_new(list_global);
	ft_putstr("\n-------------\n");
//	list_global = ft_add_data(list_global, "adwadaw");
//	list_global = ft_add_data(list_global, "HERE ");
	list_global = ft_add_data(list_global, size);
	list_global = ft_add_data(list_global, 0);
	ft_display_list(list_global);
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
	str = ft_malloc(10);

	str = ft_malloc(123);

	ft_malloc(1231231);
	ft_malloc(1231232);
	ft_malloc(1231233);
	ft_malloc(1231234);
}
