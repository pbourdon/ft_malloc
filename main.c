#include "malloc.h"

t_master	*master;

void	*ft_malloc(size_t size)
{
	void		*pointer;

	if (master == NULL)
		master = dlist_new_master(master);
	if (master == NULL)
	{
		ft_putstr(" NULL :");
		return (NULL);
	}
	pointer = ft_choose(size, master);
//	ft_putstr(" here the list of pages used :\n");
//	ft_display_list(master->pages);
	return (pointer);
}

void	ft_free(void *pointer)
{
	if (pointer != NULL)
		ft_real_free_tiny(pointer, master);
}

void	show_alloc_mem()
{
	ft_show_alloc(master);
}

void	*ft_realloc(void *ptr, size_t size)
{
	ft_free(ptr);
	return (ft_malloc(size));
}

int		main(void)
{
	char	*str;
	int		index;

	index = 0;
	str = ft_malloc(40340);
	while (index < 40340)
	{
		str[index] = 'a';
		index++;
	}
	printf("%s\n", str);
	ft_free(str);
	str = ft_malloc(450);
	index = 0;
	while (index < 450)
	{
		str[index] = 'b';
		index++;
	}
	printf ("%s\n", str);
	ft_free(str);
	str = ft_malloc(3);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	ft_putstr(str);
	ft_free(str);
//	ft_putstr(str);
	// show_alloc_mem();
	return (0);
}
