/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 07:32:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_free_point(char *map, char *piece, int i)
{
	while(map[i])
	{
		if (map[i] == '.')
			return (1);
		i++;
	}
	return (-1);
}

int	ft_free_full_place(char *map, char* piece, int i)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (piece[art.i])
	{
		if (piece[art.i] == '*' && map[art.i] != '.')
			return (0);
		art.i++;
	}
	return (1);
}

int	ft_check_piece_place(char *map, char *piece)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i])
	{
		if (ft_free_point(map, piece, art.i))
		{
			if (ft_free_full_place(map, piece, art.i))
				return (i);
		}
		art.i++;
	}
	return (0);
}

int	ft_place_piece(char *map, char *piece, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	art.i = ft_check_piece_place(map, piece);
	while (map[art.i] != '\0')
	{
		if (piece[art.i] == map[art.i])
		{
			ft_putchar(play);
		}
		art.i++;
	}
}