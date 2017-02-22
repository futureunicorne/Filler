/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:52:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 17:58:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	ft_cover_bot_rev(char *map, char *piece, int pos, int med_e, int play)
{
	int i;

	i = 0;
	while (i >= pos)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	while (i >= med_e)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_cover_top_rev(char *map, char *piece, int pos, int med_e, int play)
{
	int i;

	i = 0;
	med_e = 0;
	pos = 0;
	while (map[i])
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_cover_bottom_place(char *map, char *piece, int med_f, int play)
{
	int i;

	i = ft_strlen(map);
	med_f = 0;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}


int	ft_check_dark_side(int start, int e_co )
{
	if (start < e_co)
		return (1);
	return (0);
}
