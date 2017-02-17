/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:49:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/17 08:24:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int record_left_corner(char *piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '*')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_mediane(char *map, int med_f, int med_e)
{
	int cpt;
	int ecart;

	cpt = 0;
	ecart = med_e - med_f;
	while (med_f < med_e)
	{
		if (map[med_f] == '.')
			cpt++;
		med_f++;
	}
	ecart = (ecart / 10) * 2;
	if (cpt >= ecart)
		return (1);
	return (0);
}

int	ft_mediane_stg(char *map, char *piece, int *tab, int med_f, char play)
{
	int i;

	i = med_f;
	while (map[i] != '\0')
	{
		if (ft_check_place_i(map, piece, tab, i, play) != -1)
		{
			ft_place_i(map, piece, tab, i, play);
			return (i);
		}
		i++;
	}
	i = med_f;
	while (i >= 0)
	{
		if (ft_check_place_i(map, piece, tab, i, play) != -1)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_place_anywhere(char *map, char *piece, int *tab,char play)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_check_place_i(map, piece, tab, i, play) != -1)
			return (i);
		i++;
	}
	return (-1);
}