/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:52:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/27 18:13:34 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	ft_check_dark_side(int start, int e_co)
{
	if (start < e_co)
		return (1);
	return (0);
}

int	ft_nbr_line(char *map)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_mediane_point(char *map)
{
	int i;
	int line;
	int cpt;

	i = 0;
	line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			line++;
		i++;
	}
	line = line / 2;
	i = 0;
	cpt = 0;
	while (map[i] && cpt < line)
	{
		i++;
		if (map[i] == '\n')
			cpt++;
	}
	return (i);
}

int	ft_check_mediane(char *map, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_mediane_point(map) - 1;
	while (map[pos.i] != '\n')
	{
		if (map[pos.i] == play)
			return (1);
		pos.i--;
	}
	return (0);
}

int	check_enemy(char *map, char play2)
{
	int i;

	i = 0;
	dprintf(2, "==== %d\n", i);
	while (i >= 0)
	{
		if (map[i] == play2)
			return (i);
		i--;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == play2)
			return (i);
		i++;
	}
	return (0);
}
