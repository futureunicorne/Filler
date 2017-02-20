/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 16:45:18 by hel-hadi         ###   ########.fr       */
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

int		ft_enemy_start_place(char *map, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	art.play2 = ft_enemy_letter(play);
	while (map[art.i] != art.play2)
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

int		ft_check_battle(t_ply *ref)
{
	t_art art;
	ft_memset(&art, 0, sizeof(t_art));
	if (ref->piece == NULL)
		return (0);
	if (ref->x || ref->y)
	{
		art.x_map = ref->x;
		art.y_map = ref->y;
		art.start = ref->start;
		art.e_co  = ref->e_co;
	}
	art.i = ft_place_piece(ref->map, ref->piece, ref->play, &art);
	art.diff = record_left_corner(ref->piece);
	if (art.i >= 0)
	{
		art.x = ft_convert_x(ref->map, art.i);
		art.x = art.x - ft_correc_x(ref->piece);
		art.y = ft_convert_y(ref->map, art.i - 1);
		art.y = art.y - ft_piece_diff(ref->piece);
		ft_putnbr(art.x);
		ft_putchar(' ');
		ft_putnbr(art.y);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
