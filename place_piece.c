/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/23 20:11:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_cover_bottom_place(char *map, char *piece, int e_co, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = e_co;
	while (pos.i >= 0)
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i--;
	}
	pos.i = e_co;
	while (map[pos.i])
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i++;
	}
	return (-1);
}

int		ft_cover_top_place(char *map, char *piece, int posi, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = posi;
	while (pos.i >= 0)
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i--;
	}
	pos.i = posi;
	while (map[pos.i])
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i++;
	}
	return (-1);
}

int		ft_attack_position_classic(char *map, char *piece, char play, int e_co)
{
	t_pos	pos;
	char	play2;

	ft_memset(&pos, 0, sizeof(t_pos));
	play2 = ft_enemy_letter(play);
	pos.i = check_enemy(map, play2);
	if (e_co)
		e_co = 0;
	while (pos.i >= 0)
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i--;
	}
	pos.i = check_enemy(map, play2);
	while (map[pos.i])
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i++;
	}
	return (-1);
}

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		if (ft_check_tiers(map, 1, play) == 0)
			stg->res = ft_cover_bottom_place(map, piece, stg->e_co, play);
		if (ft_check_tiers(map, 1, play) == 1)
			stg->res =
			ft_attack_position_classic(map, piece, play, stg->e_co);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		if (ft_check_tiers(map, 0, play) == 0)
			stg->res = ft_cover_top_place(map, piece, stg->e_co, play);
		if (ft_check_tiers(map, 0, play) == 1)
			stg->res =
			ft_attack_position_classic(map, piece, play, stg->e_co);
	}
	if (stg->res == -1)
		stg->res = ft_place_anywhere(map, piece, play);
}

int		ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.pos = art->start;
	stg.e_co = art->e_co;
	stg.play2 = ft_enemy_letter(play);
	stg.med_f = ((ft_strlen(map) / 2) - ((art->x_map / 2) + 2));
	stg.med_e = ((ft_strlen(map) / 2) - ((art->x_map / 2) + art->y_map));
	ft_strategy_attack(map, piece, &stg, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
