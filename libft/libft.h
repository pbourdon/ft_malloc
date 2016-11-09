/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-maze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:43:53 by bde-maze          #+#    #+#             */
/*   Updated: 2016/11/09 19:11:50 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*p_prev;
	struct s_node	*p_next;
}					t_node;

typedef struct		s_dlist
{
	struct s_node	*p_tail;
	struct s_node	*p_head;
}					t_dlist;

typedef struct		s_arena
{
	void			*tiny;
	int				tiny_available;
	void			*small;
	int				small_available;
	void			*large;
	int				large_available;
}					t_arena;

typedef struct		s_master
{
	struct s_dlist	*tiny;
	struct s_dlist	*small;
	struct s_dlist	*large;
	struct s_arena	*arena;
}					t_master;



int				ft_isprint(int c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void*src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset (void *set, int c, size_t n);
char			*ft_itoa(long int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const*s, int fd);
void			ft_putnbr(long int n);
void			ft_putnbr_fd(long int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(char *src);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strmap(char const *s, char(*f)(char));
void			ft_strdel(char **as);
char			*ft_strmapi (char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
size_t			ft_strlen(char const *str);
char			*ft_strnstr(const char *src, const char *aig, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *src, const char *aig);
char			*ft_strnew(size_t size);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strsplit(char const *s1, char c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strstr(const char *src, const char *aig);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_joinfree(char *str, char *dst, int fre);
int				ft_ocur(char *str, char dst);
t_dlist			*ft_add_data(t_dlist *p_list, int data);
t_dlist			*nik_the_norm2(t_dlist *p_list, t_node *p_new, int i);
t_dlist			*nik_the_norm3(t_dlist *p_list, t_node *p_new, int i);
t_dlist			*dlist_new(t_dlist *p_new);
t_dlist			*dlist_append(t_dlist *p_list, int data);
t_dlist			*dlist_prepend(t_dlist *p_list, int data);
int				ft_display_list(t_dlist *p_list);
t_master		*dlist_new_master(t_master *p_master);
t_dlist			*dlist_new_mmap(t_dlist *p_new, t_arena *arena, char *adress);
t_arena			*get_adress(t_arena *arena);
t_dlist			*ft_add_data_mmap(t_dlist *p_list, int data, int choice, t_arena *arena);
t_dlist			*dlist_append_mmap(t_dlist *p_list, int data, int choice, t_arena *arena);
t_dlist			*dlist_prepend_mmap(t_dlist *p_list, int data, int choice, t_arena *arena);


#endif
