/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/03 09:00:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_little_map(char *map, int pos, int e_co)
{
	int med;

	med = ft_mediane_point(map);
	if (e_co > med && pos > med)
		return (1);
	return (0);
}

void	ft_strategy_attack2(char *map, char *piece, t_stg *stg, char play)
{
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

void	ft_strategy_attack1(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		if (ft_check_little_map(map, stg->pos, stg->e_co))
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
		else
		{
			if (last_line_inv(map, play) == 0)
			{
				stg->res = ft_attack_inv_bot(map, piece, play);
				if (stg->res == -1)
					stg->res = ft_attack_bot(map, piece, play);
			}
			else
				stg->res = ft_place_anywhere_inv(map, piece, play);
		}
	}
}

int		ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.pos = art->start;
	stg.e_co = art->e_co;
	ft_strategy_attack1(map, piece, &stg, play);
	ft_strategy_attack2(map, piece, &stg, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
