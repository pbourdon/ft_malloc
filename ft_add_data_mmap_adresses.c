/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 19:25:49 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_dlist		*ft_push_node(t_dlist *list, t_node *p_new)
{
	t_node *p_temp;

	p_temp = NULL;
	p_temp = list->p_head;
	if (p_temp)
	{
		while (p_temp)
		{
			if (p_temp->data <= p_new->data)
				p_temp = p_temp->p_next;
			else
			{

				ft_putstr("hereA");
				if (list->p_head == p_temp)
				{
	ft_putstr("here");
					return (normed(list, p_new, p_temp));
				}
				else if (list->p_tail == p_temp)
				{


					ft_putstr("alpha");
					return (normed2(list, p_temp, p_new));
				}
				else
				{
					ft_putstr("adwad");
					return (normed3(list, p_temp, p_new));
				}
			}
		}
		ft_putstr("ici");
		return (nik_the_norm3(list, p_new, 1));
	}
	ft_putstr("la");
	list = nik_the_norm3(list, p_new, 0);
	return (list);
}

t_node		*sodo_cookies2(t_node *p_new, t_master *master)
{
	if (master->available_struct > sizeof(*p_new))
	{
		p_new = (t_node *)(master->current_struct);
		master->current_struct += sizeof(*p_new) + 1;
		master->available_struct -= sizeof(*p_new) - 1;
	}
	else
	{
		return (NULL);
	}
	return (p_new);
}

t_dlist		*dlist_append_mmap_adresses(t_dlist *p_list, void *data,
				t_master *master, void *linked_page)
{
	t_node		*p_new;

	p_new = NULL;
	if (p_list != NULL)
	{
		p_new = sodo_cookies2(p_new, master);
		if (p_new != NULL)
		{
			p_new->data = data;
			if (master->temp_freed == 1)
			{
				master->temp_freed = 0;
				p_new->freed = 1;
			}
			else
				p_new->freed = 0;
			p_new = normed4(p_new, linked_page, master);
			master->current_pos += 1;
			p_list = ft_push_node(p_list, p_new);
		}
		else
			return (NULL);
	}
	return (p_list);
}

t_dlist		*ft_add_data_mmap_adresses(t_dlist *p_list, void *data,
				t_master *master, void *linked_page)
{
	if (p_list != NULL)
		p_list = dlist_append_mmap_adresses(p_list, data, master, linked_page);
	return (p_list);
}

t_dlist		*ft_check_adresses(t_dlist *p_list, void *data, t_master *master,
				void *linked_page)
{
	t_node		*p_new;

	p_new = NULL;
	if (master->available_struct <= sizeof(*p_new) * 2)
	{
		p_new = (t_node *)mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON |
					MAP_PRIVATE, -1, 0);
		if (p_new != NULL)
		{
			master->current_struct = (void *)p_new;
			master->available_struct = 4096;
			master->pages = ft_add_data_mmap_pages(master->pages, p_new, master,
				4096);
		}
	}
	return (ft_add_data_mmap_adresses(p_list, data, master, linked_page));
}
