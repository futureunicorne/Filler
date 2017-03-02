/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/02 16:34:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_attack(char *map, char *piece, char play)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_strlen(map);
	while (pos.i >= 0 && map[pos.i] != play)
	{
		pos.i--;
	}
	while (pos.i >= 0)
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i--;
	}
	return (-1);
}

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		stg->res = ft_attack_inv_bot(map, piece, play);
		if (stg->res == -1)
			stg->res = ft_attack_bot(map, piece, play);
		if (stg->res == -1)
			stg->res = ft_place_anywhere_inv(map, piece, play);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		if (last_line(map, play) == 0)
		{
			stg->res = ft_attack_inv_top(map, piece, play);
			if (stg->res == -1)
				stg->res = ft_attack(map, piece, play);
		}
		else
			stg->res = ft_place_anywhere(map, piece, play);
	}
}

int		ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.pos = art->start;
	stg.e_co = art->e_co;
	ft_strategy_attack(map, piece, &stg, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
