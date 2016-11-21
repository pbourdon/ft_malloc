/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:39:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/21 19:10:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "stdlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <sys/mman.h>

/*
** - s_master is the global struct.
**
** - s_master->large is a list which contains the adresses already given to the
** user. (like s_master->tiny && s_master->small)
**
** - s_master->pages is a list which contains the pages already mmap by the
** programm
**
** - s_master->struct is the pointer where s_master->pages can ask for
** allocation (for its own usage : to malloc the nodes)
**
** - s_master->available is the size available for the s_master->struct pointer
**
** - s_master->current_struct is the pointer where s_master->large/small/tiny
** can ask for allocation (for its own usage : to malloc the nodes)
**
** - s_master->current_available is the size available for the
** s_master->current_struct
**
** - s_master->page_small/tiny/large_client is the page where the alloc has been
** done. It's used to correctly free (as we free the page and not the adress)
**
** - s_master->current_small/tiny_client is the next pointer available and
** read to be given to the user. (don't need that for large as large
** directly mmap)
**
** - s_master->available_small/tiny_client is the available size of the pointer
** (before we need to mmap again)
**
** - s_master->temp_size/temp_freed/current_pos are used int
** ft_add_data_mmap_adresses
*/

typedef struct		s_master
{
	struct s_dlist	*tiny;
	struct s_dlist	*small;
	struct s_dlist	*large;
	struct s_dlist	*pages;
	void			*current;
	size_t			available;
	void			*current_struct;
	size_t			available_struct;
	void			*page_small_client;
	void			*page_tiny_client;
	void			*page_large_client;
	size_t			available_small_client;
	size_t			available_tiny_client;
	void			*current_small_client;
	void			*current_tiny_client;
	size_t			temp_size;
	int				current_pos;
	int				temp_freed;
}					t_master;

void				free(void *ptr);
void				show_alloc_mem(void);
void				*realloc(void *ptr, size_t size);
void				*malloc(size_t size);
void				*ft_choose(size_t size, t_master *master);
void				*tiny(size_t size, t_master *master, void *pointer,
					t_node *node);
void				*small(size_t size, t_master *master, void *pointer,
						t_node *node);
void				*large(size_t size, t_master *master);
t_dlist				*ft_add_data_mmap_pages(t_dlist *p_list, void *data,
					t_master *global, size_t size);
t_dlist				*dlist_append_mmap_pages(t_dlist *p_list, void *data,
					t_master *global, size_t size);
t_master			*dlist_new_master(t_master *master);
t_dlist				*dlist_new_mmap(t_dlist *p_new, t_master *master);
t_dlist				*ft_check(t_dlist *p_list, void *data, t_master *master,
					size_t size);
t_dlist				*ft_check_adresses(t_dlist *p_list, void *data,
					t_master *master, void *linked_page);
t_dlist				*ft_add_data_mmap_adresses(t_dlist *p_list, void *data,
					t_master *master, void *linked_page);
t_dlist				*dlist_append_mmap_adresses(t_dlist *p_list, void *data,
					t_master *master, void *linked_page);
void				show_alloc_mem(void);
void				ft_show_alloc(t_master *master);
void				ft_display_special_list(t_dlist *list);
int					ft_real_free_tiny(void *pointer, t_master *master);
void				ft_check_for_realloc(t_node *current, t_node *p_new,
						void *page, void *adress);
void				*ft_check_and_realloc(void *ptr, size_t size,
					t_master *master);
t_node				*ft_check_malloc_from_free(t_dlist *list, size_t size);
void				*ft_get_malloc_from_free(t_node *p_temp, size_t size,
					t_dlist *list, t_master *master);
void				ft_display(void *data, size_t size, int pos);
t_dlist				*normed(t_dlist *list, t_node *p_temp, t_node *p_new);
t_dlist				*normed2(t_dlist *list, t_node *p_temp, t_node *p_new);
t_dlist				*normed3(t_dlist *list, t_node *p_temp, t_node *p_new);
t_node				*normed4(t_node *p_new, void *linked_page,
					t_master *master);

#endif
