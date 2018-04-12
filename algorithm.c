/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:17:54 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 14:13:34 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillerino(int height, t_fill *lst)
{
	int		i;
	int		ptr[4];

	i = 0;
	if (lst == NULL)
	{
		return (1);
	}
	while (g_map[i] != '\0')
	{
		if (searcherino(height, i, lst, ptr))
		{
			inserterino(lst, ptr);
			if (fillerino(height, lst->next) == 1)
			{
				return (1);
			}
			deleterino(lst);
		}
		i++;
	}
	return (0);
}

int			*searcherino(int height, int index, t_fill *lst, int *ptr)
{
	int		i;
	int		j;
	int		mem;

	if (limits(height, index, lst) == 0)
		return (NULL);
	i = -1;
	j = 0;
	mem = index;
	while ((lst->figure)[++i] != '\0')
	{
		if (ft_isupper((lst->figure)[i]) && g_map[index] != '.')
			return (NULL);
		if ((lst->figure)[i] == '\n')
		{
			index = mem + height + 1;
			mem = index;
		}
		else
		{
			((lst->figure)[i] != '.') ? ptr[j++] = index : 0;
			index++;
		}
	}
	return (ptr);
}

int			limits(int height, int index, t_fill *lst)
{
	if (index % (height + 1) + lst->width <= height)
	{
		if (index / (height + 1) + lst->height <= height)
		{
			return (1);
		}
	}
	return (0);
}

void		inserterino(t_fill *lst, int *ptr)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		g_map[ptr[i]] = lst->letter;
		i++;
	}
}

void		deleterino(t_fill *lst)
{
	int		i;

	i = 0;
	while (g_map[i] != '\0')
	{
		if (g_map[i] == lst->letter)
		{
			g_map[i] = '.';
		}
		i++;
	}
}
