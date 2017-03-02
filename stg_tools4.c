/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:22:51 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/02 16:34:49 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

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

int		last_line(char *map, char play)
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

int		last_line_inv(char *map, char play)
{
	int i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] == play)
			return (1);
		i++;
	}
	return (0);
}

int		ft_attack_bot(char *map, char *piece, char play)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = 0;
	while (map[pos.i] && map[pos.i] != play)
	{
		pos.i++;
	}
	while (map[pos.i] && map[pos.i] != '\n')
		pos.i++;
	while (pos.i >= 0)
	{
		if (ft_control_check(map, piece, pos.i, play) == 1)
			return (pos.i);
		pos.i--;
	}
	return (-1);
}
