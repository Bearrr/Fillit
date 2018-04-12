/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 13:44:32 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/24 13:52:04 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char const *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void				ft_putendl(char const *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

int					ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		*ptr = 0;
		i++;
		ptr++;
	}
}
