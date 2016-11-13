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
	ft_display_list(global->tiny);
	return (pointor);
}

int		main(void)
{
	char	*str;
	int		index;
	long	page_size;

	index = 0;
	ft_putstr(" first malloc \n");
	str = ft_malloc(10);
	ft_putchar('\n');
	ft_putstr(" second malloc \n");
	str = ft_malloc(100);
	ft_putchar('\n');
	while (index < 400)
	{
		ft_putstr("\n its a new malloc of :");
		ft_putnbr(index);
		ft_putchar('\n');
		str = ft_malloc(index);
		index += 12;
	}

	return (0);
}
