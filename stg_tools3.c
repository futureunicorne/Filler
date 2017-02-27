/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:16:46 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/27 18:28:42 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_advance_diff(char *str, t_pos *pos, char play)
{
	if (str[pos->i] == play && pos->flag == 0)
	{
		if (pos->x < pos->y && pos->flag2)
		{
			pos->y = pos->x;
			pos->z = pos->i;
			pos->flag = 1;
		}
		if (!pos->flag2)
		{
			pos->y = pos->x;
			pos->z = pos->i;
			pos->flag2 = 1;
		}
	}
	if (str[pos->i] == '\n')
	{
		pos->x = -1;
		pos->flag = 0;
	}
}

int		ft_advance_point_bot(char *str, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (str[pos.i])
	{
		ft_advance_diff(str, &pos, play);
		pos.i++;
		pos.x++;
	}
	return (pos.z);
}

int		ft_advance_point_top(char *str, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_strlen(str);
	while (pos.i >= 0)
	{
		ft_advance_diff(str, &pos, play);
		pos.i--;
		pos.x++;
	}
	pos.y = ft_check_line(str) - pos.y - 1;
	return (pos.y);
}

int		ref_point(char *map, int pos)
{
	int i;

	i = pos;
	while (map[i])
	{
		if (i + ft_check_line(map) >= ((int)ft_strlen(map) - 2))
			break ;
		i = i + ft_check_line(map);
	}
	return (i);
}

int		ref_point_inv(char *map, int pos)
{
	int i;

	i = pos;
	while (i >= 0)
	{
		if ((i - ft_check_line(map)) <= 0)
			break ;
		i = i - ft_check_line(map);
	}
	return (i);
}
