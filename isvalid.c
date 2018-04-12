/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:21:22 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 16:49:44 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_isvalid(char *arg)
{
	int		fd;
	char	buf[22];
	ssize_t	scanned;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit(1);
	}
	ft_bzero(buf, 22);
	scanned = read(fd, buf, 21);
	if (scanned == 0)
		return (0);
	if (ft_norme2(scanned, buf, fd) == 0)
	{
		return (0);
	}
	close(fd);
	return (1);
}

int			enter_check(char *buf)
{
	int		i;
	int		counter;

	counter = 0;
	i = 4;
	while (i < 20)
	{
		if (buf[i] == '\n')
		{
			counter++;
		}
		i = i + 5;
	}
	if (counter == 4)
	{
		return (1);
	}
	return (0);
}

int			first_layer(char *buf)
{
	int		enter;
	int		dot;
	int		hash;
	int		i;

	enter = 0;
	dot = 0;
	hash = 0;
	i = 0;
	if (enter_check(buf) == 0)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			hash++;
		if (buf[i] == '.')
			dot++;
		i++;
	}
	if (hash == 4 && dot == 12)
	{
		if ((second_layer(buf) != 0))
			return (1);
	}
	return (0);
}

int			second_layer(char *buf)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				counter++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				counter++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				counter++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				counter++;
		}
		i++;
	}
	if (counter == 6 || counter == 8)
	{
		return (1);
	}
	return (0);
}
