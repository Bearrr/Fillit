/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:36:45 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 16:49:33 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>

char				*g_map;
typedef struct		s_fill
{
	char			figure[10];
	int				height;
	int				width;
	char			letter;
	struct s_fill	*next;
}					t_fill;
int					ft_isvalid(char *arg);
int					enter_check(char *buf);
int					first_layer(char *buf);
int					second_layer(char *buf);

int					figure_number(t_fill *ptr);
int					starting_mapsize(int figure_count);
char				*ft_realloc(int size);
int					ft_norme(char *arg, t_fill **ap);
int					ft_norme2(ssize_t scanned, char *buf, int fd);

void				to_list(t_fill **head, char *arg);
void				list_pushback(t_fill **head, char *buf, char letter);
t_fill				*new_node(char *buf, char letter);
char				*cut_horizontal(char *buf);
char				*cut_vertical(char *buf);
int					ft_tocut(char c);
void				final_cut(char *dest, char *buf, char letter);
int					width_count(char *buf);
int					height_count(char *buf);

int					fillerino(int height, t_fill *lst);
int					*searcherino(int height, int index, t_fill *lst, int *ptr);
int					limits(int height, int index, t_fill *lst);
void				inserterino(t_fill *lst, int *ptr);
void				deleterino(t_fill *lst);

void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_bzero(void *s, size_t n);
int					ft_isupper(int c);

#endif
