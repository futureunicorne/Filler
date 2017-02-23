/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:30:54 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/23 17:47:34 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_count_diff(char *str, t_pos *pos)
{
	if (str[pos->i] == '*' && pos->flag == 0)
	{
		if (pos->x < pos->y && pos->flag2)
		{
			pos->y = pos->x;
			pos->flag = 1;
		}
		if (!pos->flag2)
		{
			pos->y = pos->x;
			pos->flag2 = 1;
		}
	}
	if (str[pos->i] == '\n')
	{
		pos->x = -1;
		pos->flag = 0;
	}
}

int		ft_piece_diff(char *str)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (str[pos.i])
	{
		ft_count_diff(str, &pos);
		pos.i++;
		pos.x++;
	}
	return (pos.y);
}

int		ft_piece_diff_end(char *str)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_strlen(str);
	while (pos.i >= 0)
	{
		ft_count_diff(str, &pos);
		pos.i--;
		pos.x++;
	}
	pos.y = ft_check_line(str) - pos.y - 1;
	return (pos.y);
}

int		ft_count_piece(char *str, int lim_g, int lim_d)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (str[pos.i])
	{
		if (pos.x == lim_g)
			pos.flag = 1;
		if (pos.x == lim_d)
			pos.flag = 0;
		if ((pos.flag || str[pos.i] == '\n') && ft_star_line(str, pos.i))
		{
			pos.check++;
			pos.j++;
		}
		if (str[pos.i] == '\n')
		{
			pos.x = -1;
		}
		pos.i++;
		pos.x++;
	}
	return (pos.check);
}
