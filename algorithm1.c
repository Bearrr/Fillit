/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:17:54 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/22 11:11:47 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

int		fillerino(char *map, int height, t_fill *lst);
void	inserterino(char *map, t_fill *lst, int *ptr);
void	deleterino(char *map, t_fill *lst);
int		*searcherino(char *map, int height, int index, t_fill *lst, int *ptr);
int		limits(int height, int index, t_fill *lst);

int		limits(int height, int index, t_fill *lst)
{
	if (index % (height + 1) + lst->width <= height)
	{
		if (index / (height + 1) + lst->height <= height)
		{
			return (1);
		}
	}
	printf("check\n");
	return (0);
}

int		*searcherino(char *map, int height, int index, t_fill *lst, int *ptr)
{
	int i;
	int j;
	char *figure;
	int mem;

	printf("index: %d\n", index);
	if (limits(height, index, lst) == 0)
	{
		return (NULL);
	}
	figure = lst->figure;
	i = 0;
	j = 0;
	mem = index;
	while (figure[i] != '\0')
	{
		if (ft_isalpha(figure[i]) && map[index] != '.')
		{
			return (NULL);
		}
		if (figure[i] == '\n')
		{
			index = mem + height + 1;
			mem = index;
			i++;
		}
		else
		{
			if (figure[i] != '.')
			{
				ptr[j] = index;
				j++;
			}
			index++;
			i++;
		}
	} 
	return (ptr);
}

int		fillerino(char *map, int height, t_fill *lst)
{
	int i;
	int *ptr;

	i = 0;
	if (lst == NULL)
	{
		return (1);
	}
	ptr = (int *)malloc(sizeof(int) * 4);
	if (ptr == NULL)
	{
		return (0);
	}
	while (map[i] != '\0')
	{
		if (searcherino(map, height, i, lst, ptr))
		{
			for (int k = 0; k < 4; k++)
			{	
				printf("%d\n", ptr[k]);
			}
			inserterino(map, lst, ptr);
printf("%s", map);
			free(ptr);
 			if (fillerino(map, height, lst->next) == 1)
			{
				return (1);
			}
			deleterino(map, lst);
		}
		i++;
	}
	return (0);
}

void	inserterino(char *map, t_fill *lst, int *ptr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[ptr[i]] = lst->letter;
		i++;
	}
}

void	deleterino(char *map, t_fill *lst)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == lst->letter)
		{
			map[i] = '.';
		}
		i++;
	}
}

int main()
{
	char map[31] = {'C','C','D','D','\n','C','C','D','D','\n','.','.','.','.','\n','.','.','.','.','\n','\0'};
	printf("%s", map);

	t_fill * ptr;

    ptr = (t_fill *)malloc(sizeof(t_fill));
    ft_strcpy(ptr->figure, /*".AA\nAA.\n");*/ "AA\nAA\n");  /*"A\nA\nA\nA\n"); */
    ptr->letter = 'A';
    ptr->width = 2;
    ptr->height = 2;
	//ptr->next = NULL;
    ptr->next = (t_fill *)malloc(sizeof(t_fill));
    ft_strcpy(ptr->next->figure,  /*"A\nA\nA\nA\n");  */    ".B\n.B\nBB");
    ptr->next->letter = 'B';
    ptr->next->width = 3;
    ptr->next->height = 2;
    ptr->next->next = NULL;
	fillerino(map, 4, ptr);

printf("%s", map);
	return (0);
}
