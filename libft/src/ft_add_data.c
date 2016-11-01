/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 14:12:52 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dlist_delete(t_dlist **p_list)
{
	t_node		*p_temp;
	t_node		*p_del;

	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
		}
		p_list = NULL;
	}
}

t_dlist		*dlist_prepend(t_dlist *p_list, char *data)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->data = ft_strdup(data);
			p_new->p_prev = NULL;
			if (p_list->p_tail == NULL)
				p_list = nik_the_norm2(p_list, p_new, 0);
			else
				p_list = nik_the_norm2(p_list, p_new, 1);
		}
	}
	return (p_list);
}

t_dlist		*dlist_append(t_dlist *p_list, char *data)
{
	t_node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->data = ft_strdup(data);
			p_new->p_next = NULL;
			if (p_list->p_tail == NULL)
				p_list = nik_the_norm3(p_list, p_new, 0);
			else
				p_list = nik_the_norm3(p_list, p_new, 1);
		}
	}
	return (p_list);
}

t_dlist		*ft_add_data(t_dlist *p_list, char *data)
{
	if (p_list != NULL)
		p_list = dlist_append(p_list, data);
	p_list->pos = p_list->pos + 1;
	p_list->length = p_list->length + 1;
	return (p_list);
}

t_dlist		*ft_add_data2(t_dlist *p_list, char *data)
{
	if (p_list != NULL)
		p_list = dlist_append(p_list, data);
	p_list->pos = p_list->length + 1;
	p_list->length = p_list->length + 1;
	return (p_list);
}
