/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searcherino.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:11:29 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/17 14:33:02 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*searcherino(char *map, int height, int index, t_list *lst)
{
	char *figure;
	int res[4];
	int i;
	int j;

	figure = lst->figures;
	if (figure[i] == '.' && figure[i] + 1 == '.')
	{
		two_dots(map, height, index, figure);
	}
	else if (figure[i] == '.' && ft_isalpha(figure[i + 1]))
	{
		one_dot(map, height, index, figure);
	}

	return (res);
}
