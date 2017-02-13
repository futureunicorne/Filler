/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 17:18:42 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_check_mediane(char *map)
{
	int i;
	int j;
	int flag;

	i = (ft_strlen(map) / 2) + y_map - x_map;
	j = 0;
	while (map[i] != '\n')
	{
		if (map[i] == '.')
			flag++;
		i++;
		j++;
	}
	if (flag > (j / 10))
		return (0);
	return (1);
}

int	ft_find_star(char *piece, int flag)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	if (flag == 1)
	{
		art.i = ft_strlen(piece) - 1;
		while (art.i >= 0)
		{
			if (piece[art.i] == '*')
				return (art.i);
			art.i--;
		}
	}
	else if (flag == 1)
	{
		art.i = 0;
		while (piece[art.i])
		{
			if (piece[art.i] == '*')
				return (art.i);
			art.i++;
		}
	}
	return (-1);
}

int	ft_optimal_position(char *map, char *piece, int x_map) // cherche derniere pos depuis mediane
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	i = (ft_strlen(map) / 2) + y_map - x_map;
	while (map[art.i])
	{
		if (map[art.i] == play)
			return (i);
	}
	i = (ft_strlen(map) / 2) + y_map - x_map;
	while (i >= 0)
	{
		if (map[art.i] == play)
			return (i);
		art.i--;
	}
	return (-1);
}

int	ft_check_piece_place(char *map, char *piece) // check si endessus ou dessous de la mediane ou millieu
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	i = ft_optimal_position(map, piece, play);
	art.med = (ft_strlen(map) / 2) + y_map - x_map
	if (art.i > art.med)
		ft_place_high(map, piece, art.i);
	else if (art.i < art.med)
		ft_place_low(map, piece, art.i);
	else if (art.i >= art.med && art.i <= art.med - y_map)
		ft_close_line(map, piece, art.i)
	return ();
}

int	ft_place_piece(char *map, char *piece, char play) // fonction principale fichier
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	if (check_mediane(map, x_map, y_map) == 0)
		art.i = ft_check_piece_place(map, piece);
	else
		ft_cover_enemy_pos(char *map, char *piece);
	art.res = ft_covert_value(art.i);
	if (art.res)
	{
			return (1);
	}
	return (0);
}
