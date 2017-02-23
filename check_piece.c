/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/23 18:53:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_reduct_piece(char *str, char *dst, int lim_g, int lim_d)
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
			dst[pos.j] = str[pos.i];
			pos.j++;
		}
		if (str[pos.i] == '\n')
		{
			pos.x = -1;
		}
		pos.i++;
		pos.x++;
	}
	return (dst);
}

int		ft_count_flag(char *str, int k)
{
	int i;
	int flag;

	i = 0;
	while (i < k)
	{
		if (str[i] == '\n')
			flag = 0;
		i++;
		flag++;
	}
	return (flag);
}

void	check_piece_var(char *str, char *piece, t_pos *pos, int i)
{
	pos->k = i;
	pos->flag2 = i;
	pos->star = ft_count_stars2(piece);
	pos->flag = ft_count_flag(str, pos->k);
	pos->check = 1;
}

int		ckeck_place_piece(char *str, char *piece, int i, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(pos));
	check_piece_var(str, piece, &pos, i);
	while (piece[pos.j] && str[i])
	{
		if (str[i] == '.' && piece[pos.j] == '*')
			pos.auth++;
		if (str[i] == play && piece[pos.j] == '*')
			pos.cpt++;
		if (((piece[pos.j] != '\n') || (piece[pos.j] == '\n'
		&& piece[pos.j + 1] == '\0'))
		&& (i != (ft_check_line(str) + pos.flag2) - 1))
			pos.j++;
		if (i == ((ft_check_line(str) * pos.check) + pos.flag2) - 1)
		{
			pos.j++;
			pos.check++;
		}
		i++;
	}
	if (pos.cpt == 1 && pos.auth == pos.star - 1)
		return (1);
	return (0);
}

int		ft_control_check(char *map, char *piece, int i, char play)
{
	int		x;
	int		y;
	int		res;
	char	*dst;

	x = ft_piece_diff(piece);
	y = ft_piece_diff_end(piece);
	dst = ft_strnew(ft_count_piece(piece, x, y));
	dst = ft_reduct_piece(piece, dst, x, y);
	res = ckeck_place_piece(map, dst, i, play);
	if (res)
		return (1);
	return (0);
}
