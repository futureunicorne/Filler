/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:18:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 11:31:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	call_place(char *str, int *tab, t_car *car, t_pos *pos)
{
	if (str[car->j] == '\n')
	{
		car->diff = check_count(str) - pos->y;
		pos->x--;
		pos->y = -1 - car->diff;
	}
	if (pos->x == tab[car->k] && pos->y == tab[car->k + 1])
	{
		if (str[car->j] == '.')
		{
			str[car->j] = 'O';
			car->auth++;
		}
		car->k = car->k + 2;
	}
}

char	*ft_place_i(char *str, char *piece, int *tab, int i)
{
	t_pos pos;
	t_car car;
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	pos.star = ft_count_stars(str);
	if (str[i] == 'O')
	{
		car.auth = 0;
		ft_memset(&pos, 0, sizeof(t_pos));
		pos.star = ft_count_stars(piece);
		car.j = i;
		car.k = 0;
		while (str[car.j] ^ (car.k == pos.star * 2))
		{
			call_place(str, tab, &car, &pos);
			if (car.auth == pos.star - 1)
				return (str);
			car.j++;
			pos.y++;
		}
	}
	return (str);
}
