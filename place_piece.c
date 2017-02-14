/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/14 18:23:14 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_place_anywhere(char *map, char *piece, char play)
{
	t_art art;

	t_art art;
	ft_memset(&art, 0, sizeof(t_art));
	i = ft_start_place(map, piece, play);
	while (map[art.i])
	{
		if (ft_check_place(map, piece, art.i) == 1)
			return (art.i);
		art.i++;
	}
	return (-1);
}

int	ft_place_piece(char *map, char *piece, char play, t_art *art) // fonction principale fichier
{
	int i;

	i = ft_place_anywhere(char *map, char *piece);
	return (i);
}
