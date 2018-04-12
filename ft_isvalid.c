/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:07:00 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/12 18:10:37 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int first_layer(char *buf)
{
	int i = 0;
	int hash_counter = 0;
	int dot_counter = 0;
	int enter_counter = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			hash_counter++;
		}
		if (buf[i] == '.')
		{
			dot_counter++;
		}
		if (buf[i] == '\n')
		{
			enter_counter++;
		}
		i++;
	}
	printf("hash: %d\n", hash_counter);
	printf("dot: %d\n", dot_counter);
	printf("enter: %d\n", enter_counter);
	if ((dot_counter / hash_counter == 3) && ((enter_counter + 1) % 5 == 0))
	{
		return (1);
	}
	return (0);
}

/*int second_layer(char *buf)
{
	int i = 0;
	while (buf[i] != '\0')
	{
*/

int main()
{
	int fd;
	char buf[546];


	fd = open("palka.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("The file did not open\n");
		exit (1);
	}

	ssize_t i = read(fd, buf, 546);
	buf[i] = '\0';

	close (fd);
	//printf("i is: %zd\n", i);
	//printf("buf is: %s", buf);
	int j = first_layer(buf);
	if (j == 1)
		printf("the figures are ok\n");
	if (j == 0)
		printf("the figures are not valid\n");
	return (0);
}
