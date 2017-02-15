/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 09:37:28 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_optimal_check(char *map, char play, int flag, t_art *art)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_strlen(map) + art->y_map - art->x_map;
	while (map[pos.i])
	{
		if (map[pos.i] == play)
		{
			if (pos.cpt == flag)
				return (pos.i);
		}
		pos.i++;
	}
	pos.i = ft_strlen(map) + art->y_map - art->x_map;
	pos.cpt = 0;
	while (pos.i >= 0)
	{
		if (map[pos.i] == play)
		{
			if (pos.cpt == flag)
				return (pos.i);
		}
		pos.i--;
	}

	return (-1);
}

int	ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	int i;
	int	flag;
	int *tab;

	flag = 0;
	tab = ft_relative_pos(piece);
	ft_optimal_check(map, play, flag, *art);
	while (ft_check_place_i(map, piece, tab, ft_optimal_check(map, play, flag)) == 0)
	{
		if (ft_optimal_check(map, play, flag == -1))
			break;
		flag++;
	}
	free(tab);
	i = ft_optimal_check(map, play, flag);
	return (i);
}
