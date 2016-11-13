/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/11/13 19:14:45 by pbourdon         ###   ########.fr       */
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


void			*ft_choose(size_t size, t_master *master);
void			*tiny(size_t size, t_master *master);
void			*small(size_t size, t_master *master);
void			*large(size_t size, t_master *master);
t_dlist			*ft_add_data_mmap_pages(t_dlist *p_list, void *data, t_master *global);
t_dlist			*dlist_append_mmap_pages(t_dlist *p_list, void *data, t_master *global);
t_master		*dlist_new_master(t_master *master);
t_dlist			*dlist_new_mmap(t_dlist *p_new, t_master *master);
t_dlist			*ft_check(t_dlist *p_list, void *data, t_master *master);
t_dlist			*ft_check_adresses(t_dlist *p_list, void *data, t_master *master, size_t size);
t_dlist			*ft_add_data_mmap_adresses(t_dlist *p_list, void *data, t_master *master, size_t size);
t_dlist			*dlist_append_mmap_adresses(t_dlist *p_list, void *data, t_master *master, size_t size);
void			show_alloc_mem(void);
void			ft_show_alloc(t_master *master);
void			ft_display_special_list(t_dlist *list);


#endif
