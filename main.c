/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:19:37 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 15:25:45 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_realloc(int size)
{
	int		i;
	int		len;
	char	*ptr;

	if (g_map != NULL)
		free(g_map);
	len = (size + 1) * size;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = '.';
		i++;
	}
	ptr[i] = '\0';
	i = 0;
	while (i < len)
	{
		ptr[size + i] = '\n';
		i = i + size + 1;
	}
	return (ptr);
}

int			figure_number(t_fill *ptr)
{
	int	i;

	i = 0;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int			starting_mapsize(int figure_count)
{
	int size;

	size = 2;
	while (figure_count * 4 > size * size)
	{
		size++;
	}
	return (size);
}

int			ft_norme(char *arg, t_fill **ap)
{
	int		figure_count;

	figure_count = 0;
	if (ft_isvalid(arg))
	{
		to_list(ap, arg);
		figure_count = figure_number(*ap);
	}
	else if (arg[0] == '\0')
	{
		ft_putendl("error");
		return (0);
	}
	else
	{
		ft_putendl("error");
		return (0);
	}
	return (figure_count);
}

int			main(int argc, char **argv)
{
	t_fill	*head;
	int		size;
	int		figure_count;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit your_file");
		return (1);
	}
	head = NULL;
	if (!(figure_count = ft_norme(argv[1], &head)))
		return (2);
	size = starting_mapsize(figure_count);
	g_map = NULL;
	if ((g_map = ft_realloc(size)))
	{
		while (!fillerino(size, head))
		{
			size++;
			g_map = ft_realloc(size);
		}
	}
	ft_putstr(g_map);
	return (0);
}
