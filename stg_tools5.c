/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:09:36 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/01 19:15:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_count_attack(t_pos *pos, int flag)
{
	if (pos->i == pos->place - 2 && flag == 0)
		pos->flag = 1;
	if (pos->i == pos->place - 1 && flag == 1)
		pos->flag = 1;
	if (pos->i == pos->place + 1 && flag == 0)
		pos->flag = 0;
	if (pos->i == pos->place + 2 && flag == 1)
		pos->flag = 0;
}

void	ft_inv_bot(char *map, t_pos *pos)
{
	if (pos->i == pos->diff)
		pos->star++;
	pos->i = pos->i + ft_check_line(map);
	if ((pos->star >= 1 && pos->star <= 5) && ((pos->i >= (int)ft_strlen(map) - 1)))
		pos->i = pos->diff;
	if (pos->i >= (int)ft_strlen(map) - 1)
	{
		pos->j++;
		pos->i = pos->j;
	}
}

int		ft_attack_inv_bot(char *map, char *piece, char play)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.cpt = ft_advance_point_bot(map, play);
	pos.x = ref_point_inv(map, pos.cpt);
	pos.place = ref_point_inv(map, pos.cpt);
	pos.diff = ref_point_inv(map, pos.cpt) -2;
	while (pos.i >= 0)
	{
		//printf(	"===== %d\n", pos.i);
		if (pos.i == pos.x + 1)
			break ;
		ft_count_attack(&pos, 0);
		if (pos.flag == 1)
		{
			if (ft_control_check(map, piece, pos.i, play) == 1)
				return (pos.i);
		}
		ft_inv_bot(map, &pos);
	}
	return (-1);
}

void 	ft_inv_top(char *map, t_pos *pos)
{
	if (pos->i == pos->diff)
	{
		pos->star++;
	}
	pos->i = pos->i - ft_check_line(map);
	if ((pos->star >= 1 && pos->star <= 8) && (pos->i < 0))
	{
		pos->i = pos->diff;
	}
	if (pos->i < 0)
	{
		pos->j++;
		pos->i = pos->place + pos->j;
	}
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
		if (pos.i == (int)ft_strlen(map) - 2)
			break ;
		ft_count_attack(&pos, 1);
		if (pos.flag == 1)
		{
			if (ft_control_check(map, piece, pos.i, play) == 1)
				return (pos.i);
		}
		ft_inv_top(map, &pos);
	}
	return (-1);
}
