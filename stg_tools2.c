/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:52:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 11:51:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	ft_cover_bot_rev(char *map, char *piece, int e_co, int med_e, int play)
{
	int i;

	i = 0;
	if (e_co < 0)
		e_co = 0;
	while (i <= med_e)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_cover_top_rev(char *map, char *piece, int place, int med_e, int play)
{
	int i;

	i = med_e;
	if (place < 0)
		place = 0;
	while (map[i])
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_cover_bottom_place(char *map, char *piece, int e_co, int med_e, int play)
{
	int i;

	i = e_co;
	while (map[i] != '\0')
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	i = e_co;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_cover_top_place(char *map, char *piece, int place, int med_e, int play)
{
	int i;

	i = place;
	while (i <= med_e)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	i = place;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int	ft_check_dark_side(int e_corp, int med_e)
{
	if (e_corp > med_e)
		return (1);
	return (0);
}
