/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cut1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 14:34:41 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/26 15:31:22 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_list(t_fill **head, char *arg)
{
	char	buf[22];
	char	letter;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		exit(1);
	}
	letter = 'A';
	while (read(fd, buf, 21) != 0)
	{
		buf[20] = '\0';
		list_pushback(head, buf, letter);
		letter++;
	}
	close(fd);
}

void		list_pushback(t_fill **head, char *buf, char letter)
{
	t_fill	*temp;

	if (*head == NULL)
	{
		*head = new_node(buf, letter);
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node(buf, letter);
}

t_fill		*new_node(char *buf, char letter)
{
	t_fill	*ptr;

	ptr = (t_fill *)malloc(sizeof(t_fill));
	if (ptr == NULL)
	{
		return (NULL);
	}
	cut_horizontal(buf);
	cut_vertical(buf);
	final_cut(ptr->figure, buf, letter);
	ptr->letter = letter;
	ptr->width = width_count(ptr->figure);
	ptr->height = height_count(ptr->figure);
	ptr->next = NULL;
	return (ptr);
}

char		*cut_horizontal(char *buf)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	while (i < 20)
	{
		counter = 0;
		j = i;
		while (buf[i] != '\n')
		{
			if (buf[i] == '.')
				counter++;
			i++;
		}
		if (counter == 4)
		{
			while (buf[j] != '\n')
				buf[j++] = '*';
			buf[j] = '*';
		}
		i++;
	}
	return (buf);
}

char		*cut_vertical(char *buf)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (ft_tocut(buf[i]) && ft_tocut(buf[i + 5])
		&& ft_tocut(buf[i + 10]) && ft_tocut(buf[i + 15]))
		{
			buf[i] = '*';
			buf[i + 5] = '*';
			buf[i + 10] = '*';
			buf[i + 15] = '*';
		}
		i++;
	}
	return (buf);
}
