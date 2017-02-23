/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:22:11 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/23 18:37:04 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_diff(char *str, int i)
{
	int j;
	int res;

	j = 0;
	res = 0;
	while (j < i)
	{
		if (str[j] == '\n')
			res = 0;
		j++;
		res++;
	}
	return (res);
}

int		ft_check_line(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

int		ft_count_stars2(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i])
	{
		if (piece[i] == '*')
			cpt++;
		i++;
	}
	return (cpt);
}

int		ft_star_line(char *str, int i)
{
	if (str[i] == '\n')
	{
		i--;
		while (str[i] != '\n' && i >= 0)
		{
			if (str[i] == '*')
				return (1);
			i--;
		}
	}
	else
	{
		while (str[i] != '\n' && i >= 0)
			i--;
		i++;
		while (str[i] != '\n')
		{
			if (str[i] == '*')
				return (1);
			i++;
		}
	}
	return (0);
}
