/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cut2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 14:55:50 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 16:54:55 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_tocut(char c)
{
	if (c == '.' || c == '*')
	{
		return (1);
	}
	return (0);
}

void		final_cut(char *dest, char *buf, char letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '*')
		{
			if (buf[i] == '#')
			{
				dest[j] = letter;
				j++;
			}
			else
			{
				dest[j] = buf[i];
				j++;
			}
		}
		i++;
	}
	dest[j] = '\0';
}

int			height_count(char *buf)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			res++;
		}
		i++;
	}
	return (res);
}

int			width_count(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	return (i);
}

int			ft_norme2(ssize_t scanned, char *buf, int fd)
{
	char	c;

	while (scanned != 0)
	{
		c = buf[20];
		if (scanned < 20 || (first_layer(buf) == 0))
		{
			return (0);
		}
		ft_bzero(buf, 22);
		scanned = read(fd, buf, 21);
	}
	if (c != '\0')
	{
		return (0);
	}
	return (1);
}
