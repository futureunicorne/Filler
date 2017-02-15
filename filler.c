/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 17:28:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_start_place(char *map, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play)
		art.i++;
	return (art.i);
}

int		ft_enemy_start_place(char *map, char play2)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play2)
		art.i++;
	return (art.i);
}

char	ft_enemy_letter(int play)
{
	int play2;

	if (play == 'O')
		play2 = 'X';
	else
		play2 = 'O';
	return (play2);
}



int		ft_check_battle(char *map, char *piece, char play, int x_map, int y_map)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));

	if (piece == NULL)
		return (0);
	if (x_map || y_map)
	{
		x_map =  art.x_map;
		y_map =  art.y_map;
	}
	art.i = ft_place_piece(map, piece, play, &art);
	art.diff = record_left_corner(piece);
	if (art.i >= 0)
	{
		art.x = ft_convert_x(map, art.i - art.diff);
		art.y = ft_convert_y(map, art.i - art.diff) - 1;
		ft_putnbr(art.x);
		ft_putchar(' ');
		ft_putnbr(art.y);
		ft_putchar('\n');
	}
	else
		return (0);
	return (1);
}
