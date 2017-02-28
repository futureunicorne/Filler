/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/28 19:40:26 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_count_attack(t_pos *pos)
{
	if (pos->i == pos->place)
		pos->flag = 1;
	if (pos->i == pos->place + 2)
		pos->flag = 0;
}

int		ft_attack_inv_bot(char *map, char *piece, char play)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.cpt = ft_advance_point_bot(map, play);
	pos.i = ref_point_inv(map, pos.cpt) -2;
	pos.place = ref_point_inv(map, pos.cpt) -2;
	pos.diff = ref_point_inv(map, pos.cpt) - 2;
	while (pos.i >= 0)
	{
		printf("i == %d\n", pos.i );
		if (pos.i <= 0)
			break ;
		ft_count_attack(&pos);
		if (pos.flag == 1)
		{
			if (ft_control_check(map, piece, pos.i, play) == 1)
				return (pos.i);
		}
		if (pos.i == pos.diff)
			pos.star++;
		pos.i = pos.i + ft_check_line(map);
		if ((pos.star >= 1 && pos.star <= 5) && ((pos.i >= (int)ft_strlen(map) - 1) || map[pos.i] == play))
		{
			pos.i = pos.diff;
		}
		if (map[pos.i - (ft_check_line(map) * 4)] == play)
		{
			pos.j++;
			pos.i = pos.place - pos.j;
		}
		if (pos.i >= (int)ft_strlen(map) - 1)
		{
			pos.j++;
			pos.i = pos.place - pos.j;
		}
	}
	return (-1);
}

int		ft_attack_inv_top(char *map, char *piece, char play)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.cpt = ft_advance_point_top(map, play);
	pos.i = ref_point(map, pos.cpt) - 1;
	pos.place = ref_point(map, pos.cpt) - 1;
	pos.diff = ref_point(map, pos.cpt);
	while (map[pos.i])
	{
		if (pos.i == (int)ft_strlen(map) - 1)
			break ;
		ft_count_attack(&pos);
		if (pos.flag == 1)
		{
			if (ft_control_check(map, piece, pos.i, play) == 1)
				return (pos.i);
		}
		if (pos.i == pos.diff)
		{
			pos.star++;
		}
		pos.i = pos.i - ft_check_line(map);
		if ((pos.star >= 1 && pos.star <= 8) && (pos.i < 0 || map[pos.i] == play))
		{
			pos.i = pos.diff;
		}
		if (map[pos.i + (ft_check_line(map) * 4)] == play)
		{
			pos.j++;
			pos.i = pos.place + pos.j;
		}
		if (pos.i < 0)
		{
			pos.j++;
			pos.i = pos.place + pos.j;
		}

	}
	return (-1);
}

int 	last_line(char *map, char play)
{
	int i;

	i = ft_strlen(map) - 2;
	while (map[i] != '\n' && i >= 0)
	{
		if (map[i] == play)
			return (1);
		i--;
	}
	return (0);
}

int 	last_line_bot(char *map, char play)
{
	int i;

	i = ft_strlen(map) - 2;
	while (map[i] != '\n' && i >= 0)
	{
		if (map[i] == play)
			return (1);
		i--;
	}
	return (0);
}

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{

	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		stg->res = ft_attack_inv_bot(map, piece, play);
		//if (stg->res == -1)
		//	stg->res = ft_attack(map, piece, play);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		if (last_line(map, play) == 0)
		{
			stg->res = ft_attack_inv_top(map, piece, play);
			if (stg->res == -1)
				stg->res = ft_attack(map, piece, play);
		}
		else
		{
			stg->res = ft_place_anywhere(map, piece, play);
		}
	}
	//if (stg->res == -1)
	//	stg->res = ft_place_anywhere(map, piece, play);
	stg->res = ft_attack_inv_bot(map, piece, play);

}

int		ft_place_piece(char *map, char *piece, char play)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	ft_strategy_attack(map, piece, &stg, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
