/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 17:54:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_attack_special_part3(char *map, char *piece, int pos, char play) // du bas a droit vers le haut
{
	int i;
	int chk;
	int diff;
	int half;

	half = ft_check_half_line(map) / 2;
	dprintf(2, "haaaaaaalf ================ %d\n", half);
	diff = 0;
	i = 819;

	pos = 0;
	i = ft_strlen(map);
	while (i >= 0)
	{
		if (map[i] == '\n')
		{
			chk = -1;
			diff++;
		}
		if (chk <= half + diff)
		{
			if (ft_control_check(map, piece, i, play) == 1)
				return (i);
		}
		i--;
		chk++;
	}
	return (-1);
}

int		ft_attack_special_part2(char *map, char *piece, int pos, char play)
{
	int i;
	int chk;
	int diff;
	int half;

	half = ft_check_half_line(map) / 5;
	dprintf(2, "haaaaaaalf ================ %d\n", half);
	diff = 0;

	pos = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			chk = -1;
			diff = diff + 1;
		}
		if (chk <= half + diff)
		{
			if (ft_control_check(map, piece, i, play) == 1)
				return (i);
		}
		i++;
		chk++;
	}
	return (-1);
}



int		ft_attack_position(char *map, char *piece, int e_co, char play)
{
	int i;

	i = e_co;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	i = e_co;
	while (map[i])
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_right_line(char *map, char *piece, int pos, char play)
{
	int i;
	int chk;
	int diff;
	int half;

	half = ft_check_half_line(map) / 1;
	dprintf(2, "haaaaaaalf ================ %d\n", half);
	diff = 0;

	pos = 0;
	i = 161;
	half = 17;
	chk = 0;
	while (i >= 0)
	{
		if (map[i] == '\n')
		{
			chk = -1;
			diff = diff - 1;
		}
		if (chk < half + diff)
		{
			if (ft_control_check(map, piece, i, play) == 1)
				return (i);
		}
		i--;
		chk++;
	}
	return (-1);
}


void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		stg->res = ft_right_line(map, piece, stg->pos, play);
		if (stg->res == -1)
			stg->res = ft_attack_position(map, piece, stg->e_co, play);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		if (ft_check_tiers(map, 0, play) == 0)
			stg->res = ft_attack_special_part3(map, piece, stg->pos, play);
		if (ft_check_tiers(map, 0, play) == 1)
			stg->res = ft_attack_position(map, piece, stg->e_co, play);
		if (stg->res == -1)
			stg->res = ft_attack_position(map, piece, stg->e_co, play);
	}
	//stg->res = ft_right_line(map, piece, stg->pos, play);

	//if (stg->res == -1)
	//	stg->res = ft_place_anywhere(map, piece, play);
}

int	ft_place_piece(char *map, char *piece, char play, t_art *art)
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
