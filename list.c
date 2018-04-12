/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:59:33 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/21 10:45:15 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include <string.h>

char	*cut_horizontal(char *buf);
char	*cut_vertical(char *buf);
int		ft_tocut(char c);
void	final_cut(char *dest, char *buf, char letter);
void	list_pushback(t_fill **head, char *buf, char letter);
int		height_count(char *buf);
int		width_count(char *buf);

t_fill		*new_node(char *buf, char letter)
{
	t_fill * ptr;

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

void	list_pushback(t_fill **head, char *buf, char letter)
{
	t_fill *temp;


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

char	*cut_horizontal(char *buf)
{
	int i;
	int j;
	int counter;

	i = 0;
	while (i < 20)
	{
		counter = 0;
		j = i;
		while (buf[i] != '\n')
		{
			if (buf[i] == '.')
			{
				counter++;
			}
			i++;
		}
		if (counter == 4)
		{
			while (buf[j] != '\n')
			{
				buf[j] = '*';
				j++;
			}
			buf[j] = '*';
		}
		i++;
	}
	return (buf);
}

char	*cut_vertical(char *buf)
{
	int i;

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

int		ft_tocut(char c)
{
	if (c == '.' || c == '*')
	{
		return (1);
	}
	return (0);
}

void	final_cut(char *dest, char *buf, char letter)
{
	int i;
	int j;

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

int		height_count(char *buf)
{
	int i;
	int res;

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

int		width_count(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	return (i);
}

int		main()
{
	t_fill	*head;
	char buf[22];
	char letter;
	int fd;
	
	fd = open("palka.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("the file did not open\n");
		exit (1);
	}
	letter = 'A';
	while (read(fd, buf, 21) != 0)
	{
		buf[20] = '\0';
		//printf("buf\n%s", buf);
		list_pushback(&head, buf, letter);
		//printf("buf:\n%s\n", buf);
		//printf("letter in the node: %c\n", head->letter);
		//printf("next in the node: %p\n", head->next);
		letter++;
	}
printf("figure in the node:\n%s\n", head->figure);
printf("figure in the node:\n%s\n", head->next->figure);
printf("figure in the node:\n%s\n", head->next->next->figure);
printf("width of the first figure:\n%d\n", head->width);
printf("height of the first figure:\n%d\n", head->height);
printf("width of the 2nd figure:\n%d\n", head->next->width);
printf("height of the 2nd figure:\n%d\n", head->next->height);
printf("width of the 3rd figure:\n%d\n", head->next->next->width);
printf("height of the 3rd figure:\n%d\n", head->next->next->height);

	close (fd);
	return (0);
}
