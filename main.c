#include "malloc.h"

t_master	*global;

void	*ft_malloc(size_t size)
{
	void		*pointor;

	if (global == NULL)
		global = dlist_new_master(global);
	if (global == NULL)
	{
		ft_putstr(" NULL :");
		return (NULL);
	}
	pointor = ft_choose(size, global);
	return (pointor);
}

void	show_alloc_mem()
{
	ft_show_alloc(global);
}

int		main(void)
{
	char	*str;
	int		index;
	long	page_size;

	index = 0;
	str = ft_malloc(40340);
	while (index < 40340)
	{
		str[index] = 'a';
		index++;
	}
	printf("%s\n", str);
	str = ft_malloc(450);
	index = 0;
	while (index < 450)
	{
		str[index] = 'b';
		index++;
	}
	printf ("%s\n", str);
	show_alloc_mem();
	return (0);
}
