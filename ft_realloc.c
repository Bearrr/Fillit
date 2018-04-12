/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:54:44 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/15 16:31:36 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_realloc(char *ptr, int size)
{
	int i;
	int len;

	if (ptr != NULL)
	{
		free (ptr);
	}	
	len = (size + 1) * size;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
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

int main()
{
	char *ptr;
	int size;

	ptr = NULL;
	size = 1;
	while (size < 5)
	{
		printf("%s\n", ft_realloc(ptr, size));
		size++;
	}
	return (0);
}
