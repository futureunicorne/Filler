/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:18:23 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 10:37:53 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	call_place(char *str, int *tab, t_car *car, t_pos *pos, char *dst)
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
			dst[car->j] = 'o';
			car->auth++;
		}
		else if (str[car->j] == 'O' && pos->cpt < 2)
			pos->cpt++;
		car->k = car->k + 2;
	}
}

char	*ft_place_i(char *str, char *piece, int *tab, int i, char play)
{
	t_pos pos;
	t_car car;
	char *dst;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	dst = ft_strdup(str);
	pos.star = ft_count_stars(str);
	if (str[i] == play || str[i] == '.')
	{
		car.auth = 0;
		ft_memset(&pos, 0, sizeof(t_pos));
		pos.star = ft_count_stars(piece);
		car.j = i;
		car.k = 0;
		while ((str[car.j] != '\0') ^ (car.k == pos.star * 2))
		{
			call_place(str, tab, &car, &pos, dst);
			//printf("auth1 = %d\n",car.auth);
			//printf("cpt1  = %d\n",pos.cpt);
			//printf("star  = %d\n",pos.star -1);
			//printf("j  = %d\n",car.j);
			if (car.auth == pos.star - 1 && pos.cpt == 1)
			{
				return (dst);
			}
			car.j++;
			pos.y++;
		}
	}
	return (str);
}
