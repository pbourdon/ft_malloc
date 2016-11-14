/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/14 14:29:07 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SH_H
# define SH_H

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
# include "libft/libft.h"
# include <sys/ioctl.h>
# include <sys/mman.h>


typedef struct		s_master
{
	struct s_dlist	*tiny;
	struct s_dlist	*small;
	struct s_dlist	*large; // struct which lists			the adresses already given
	struct s_dlist	*pages; // struct which list	s the pages already used
	void			*current; // here it's the alloc of pa			ges_struct
	size_t			available;
	void			*current_struct; // here it's the alloc of structs (tiny, small & large which list the adresses already given)
	size_t			available_struct;
	void			*page_small_client;
	void			*page_tiny_client;
	void			*page_large_client;
	size_t			available_small_client;
	size_t			available_tiny_client;
	void			*current_small_client;
	void			*current_tiny_client;
}					t_master;

	void			*ft_choose(size_t size, t_master *master);
	void			*tiny(size_t size, t_master *master);
	void			*small(size_t size, t_master *master);
	void			*large(size_t size, t_master *master);
	t_dlist			*ft_add_data_mmap_pages(t_dlist *p_list, void *data, t_master *global, size_t size);
	t_dlist			*dlist_append_mmap_pages(t_dlist *p_list, void *data, t_master *global, size_t size);
	t_master		*dlist_new_master(t_master *master);
	t_dlist			*dlist_new_mmap(t_dlist *p_new, t_master *master);
	t_dlist			*ft_check(t_dlist *p_list, void *data, t_master *master, size_t size);
	t_dlist			*ft_check_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page);
	t_dlist			*ft_add_data_mmap_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page);
	t_dlist			*dlist_append_mmap_adresses(t_dlist *p_list, void *data, t_master *master, void *linked_page);
	void			show_alloc_mem(void);
	void			ft_show_alloc(t_master *master);
	void			ft_display_special_list(t_dlist *list);
	int				ft_real_free_tiny(void *pointer, t_master *master);

#endif
