/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:49:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 14:43:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int record_left_corner(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i])
	{
		if (piece[i] == '\n')
			cpt = -1;
		if (piece[i] == '*')
			return (cpt);
		cpt++;
		i++;
	}
	return (-1);
}

int	ft_place_anywhere(char *map, char *piece, char play)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}
