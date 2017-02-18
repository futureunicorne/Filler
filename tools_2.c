/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:12:01 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 13:45:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	ft_convert_x(char *map, int conv)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] && art.i < conv)
	{
		if (map[art.i] == '\n')
			art.x++;
		art.i++;
	}
	return (art.x);
}

int	ft_convert_y(char *map, int conv)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (art.i<= conv)
		art.i++;
	while (map[art.i] != '\n')
	{
		art.i--;
		art.y++;
	}
	return (art.y - 1);
}

int	ft_count_stars(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '*')
			cpt++;
		i++;
	}
	return (cpt);
}

int				check_count(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}
