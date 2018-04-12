/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:10:27 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/22 15:15:18 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	int size;
	int figure_num;

	figure_num = 4;
	size = 2;
	while (figure_num * 4 > size * size)
	{
		size++;
	}
	printf("%d\n", size);
	return (0);
}
