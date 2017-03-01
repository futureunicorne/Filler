/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:49:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/28 20:28:43 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		record_left_corner(char *piece)
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

int		ft_place_anywhere(char *map, char *piece, char play)
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

int		ft_place_anywhere_inv(char *map, char *piece, char play)
{
	int i;

	i = ft_strlen(map) - 2;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_check_bound(char *map, int flag)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.cpt = ft_nbr_line(map) / 4;
	if (flag == 0)
	{
		pos.i = 0;
		while (map[pos.i] && pos.auth < pos.cpt)
		{
			if (map[pos.i] == '\n')
				pos.auth++;
			pos.i++;
		}
	}
	if (flag == 1)
	{
		pos.i = ft_strlen(map) - 2;
		while (pos.i >= 0 && pos.auth < pos.cpt)
		{
			if (map[pos.i] == '\n')
				pos.auth++;
			pos.i--;
		}
	}
	return (pos.i - 1);
}

int		ft_check_tiers(char *map, int flag, char play)
{
	int i;
	int cpt;

	cpt = ft_check_bound(map, flag);
	if (flag == 0)
	{
		i = 0;
		while (i < cpt)
		{
			if (map[i] == play)
				return (1);
			i++;
		}
	}
	if (flag == 1)
	{
		i = ft_strlen(map);
		while (i > cpt)
		{
			if (map[i] == play)
				return (1);
			i--;
		}
	}
	return (0);
}
