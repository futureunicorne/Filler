/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 17:01:06 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_start_place(char *map, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play)
		art.i++;
	printf("depart = %d\n", art.i);
	return (art.i);
}

int		ft_enemy_start_place(char *map, char play2)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (map[art.i] != play2)
		art.i++;
	printf("depart enemy= %d\n", art.i);
	return (art.i);
}

int		*ft_check_battle(char *map, char *piece, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	piece = NULL;
	art.pos = ft_start_place(map, play);
	if (play == 'O')
		art.play2 = 'X';
	else
		art.play2 = 'O';
	art.pos_ad = ft_enemy_start_place(map, art.play2);

	return (0);
}
