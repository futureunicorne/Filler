/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/01 19:23:49 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	/*
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
	*/
	stg->res = ft_place_anywhere(map, piece, play);
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
