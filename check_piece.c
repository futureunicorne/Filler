/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 11:35:14 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_diff(char *str, int i)
{
	int j;
	int res;

	j = 0;
	res = 0;
	while (j < i)
	{
		if (str[j] == '\n')
			res = 0;
		j++;
		res++;
	}
	return (res);
}

int		ft_check_line(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

int		ft_count_stars2(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i])
	{
		if (piece[i] == '*')
			cpt++;
		i++;
	}
	return (cpt);
}

void 	ft_count_diff(char *str, t_pos *pos)
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

int			ft_star_line(char *str, int pos)
{
	int i;

	i = pos;
	if (str[i] == '\n')
	{
		i--;
		while (str[i] != '\n' && i >= 0)
		{
			if (str[i] == '*')
				return (1);
			i--;
		}
	}
	else
	{
		while (str[i] != '\n' && i >= 0)
			i--;
		i++;
		while (str[i] != '\n')
		{
			if (str[i] == '*')
				return (1);
			i++;
		}
	}
	return (0);
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
char		*ft_reduct_piece(char *str, char *dst, int lim_g, int lim_d)
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

int ft_strlim(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'O')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int		ckeck_place_piece(char *str, char *piece, int i, char play)
{
	int j;
	int k;
	int l;
	t_pos pos;

	j = 0;
	k = i;
	l = 0;
	ft_memset(&pos, 0, sizeof(pos));
	pos.flag2 = i;
	pos.star = ft_count_stars2(piece);
	ft_strlim(str);
	while (l < k)
	{
		if (str[l] == '\n')
			pos.flag = 0;
		l++;
		pos.flag++;
	}
	pos.check = 1;
	while (piece[j] && str[i])
	{
		if (str[i] == '.' && piece[j] == '*')
			pos.auth++;
		if (str[i] == play && piece[j] == '*')
			pos.cpt++;
		if ((piece[j] != '\n'|| (piece[j] == '\n' && piece[j + 1] == '\0')) &&
		(i != (ft_check_line(str) + pos.flag2) - 1))
			j++;
		if (i == ((ft_check_line(str) * pos.check) + pos.flag2) - 1)
		{
			j++;
			pos.check++;
		}
		i++;

	}
	if (pos.cpt == 1 && pos.auth == pos.star - 1)
		return (1);
	return (0);
}

int	ft_control_check(char *map, char *piece, int i, char play)
{
	int x;
	int y;
	int res;
	char *dst;

	x = ft_piece_diff(piece);
	y = ft_piece_diff_end(piece);
	dst = ft_strnew(ft_count_piece(piece, x, y));
	dst = ft_reduct_piece(piece, dst, x, y);
	res = ckeck_place_piece(map, dst, i, play);
	if (res)
		return (1);
	return (0);
}
