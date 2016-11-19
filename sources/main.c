#include "malloc.h"
#include <strings.h>
#include <stdlib.h>
#define M (1024 * 1024)

t_master	*master;

void	*malloc(size_t size)
{
	void		*pointer;

	if (master == NULL)
		master = dlist_new_master(master);
	if (master == NULL)
	{
		ft_putstr(" NULL :");
		return (NULL);
	}
	ft_putnbr(master->current_pos);
	ft_putstr(" trying to malloc size of : ");
	ft_putnbr(size);
	ft_putchar('\n');
	pointer = ft_choose(size, master);
//	ft_putstr(" pointer : ");
//	ft_putnbr((size_t)pointer);
//	ft_putstr(" of size : ");
//	ft_putnbr(size);
//	ft_putchar('\n');
	return (pointer);
}

void	free(void *ptr)
{
	if (ptr != NULL)
		ft_real_free_tiny(ptr, master);
}

void	show_alloc_mem()
{
	ft_show_alloc(master);
}

void	*realloc(void *ptr, size_t size)
{
	if (ptr != NULL && size > 0)
		return (ft_check_and_realloc(ptr, size, master));
	else if (ptr != NULL && size <= 0)
		free(ptr);
	else if (ptr == NULL && size > 0)
		return (malloc(size));
	return (NULL);
}

void	print(char *s)
{
	write (1, s, strlen(s));
}
/*
int		main(void)
{
	char	*str;
	char	*str2;
	int		index = 0;


	while (index < 1024)
	{
		str = ft_malloc(1024);
		str[0] = 42;
		index++;
	}
	show_alloc_mem();
return (0); 

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
	
}*/
