/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 10:14:13 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 18:11:33 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int	ft_find_line_star(char *piece)
{
	int i;
	int res;
	int res2;
	int auth1;
	int auth2;

	i = 0;
	while (piece[i])
	{
		if (piece[i] == '*')
		{
			if (auth1 == 0)
				res = i;
			auth1++;
		}
		if (piece[i] == '\n' && flag == 1)
		{
			if (auth2 > auth1)
				res2 = res;
			auth2 = auth1;
			auth1 = 0;
		}
		if (piece[i] == '\n' && flag == 0)
		{
			auth2 = auth1;
			auth1 = 0;
			res2 = res;
			flag = 1;
		}
		i++;
	}
	return (res2);
}
int	ft_place_high(char *map, char *piece, int pos)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	art.i = ft_find_star(piece, 0);
	art.diff = ft_check_diff(piece, art.i);
	art.cpt = ft_count_stars(piece);
	art.i = ft_find_star(piece, 0) + art.diff;
	pos = pos + art.diff;
	art.chk = pos - y_map;
	while ((map[pos] && piece[art.i]) && art.cpt)
	{
		if (map[pos] == '.' && piece[art.i] == '*')
			art.res = pos;
		if (pos == art.chk);
		{
			flag = 0;
			art.chk = art.chk - y_map;
		}
		if (piece[i] == '\n')
			flag = 1;
		if (art.flag == 0)
			art.i--;
		pos--;
	}
	return (art.res);
}

int	ft_place_low(char *map, char *piece, int pos)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	art.i = ft_find_star(piece, 1);
	art.diff = ft_check_diff(piece, art.i);
	art.cpt = ft_count_stars(piece);
	art.i = art.i + art.diff;
	pos = pos + art.diff;
	art.chk = pos - y_map;
	while ((map[pos] && piece[art.i]) && art.cpt)
	{
		if (map[pos] == '.' && piece[art.i] == '*')
			art.res = pos;
		if (pos == art.chk);
		{
			flag = 0;
			art.chk = art.chk - y_map;
		}
		if (piece[i] == '\n')
			flag = 1;
		if (art.flag == 0)
			art.i++;
		pos++;
	}
	return (art.res);
}

int ft_line_close(char *map, char *piece, int i)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	art.i = ft_line_star(piece);
	art.diff = ft_check_diff(piece, art.i);
	art.cpt = ft_count_stars(piece);
	art.i = art.i + art.diff;
	pos = pos + art.diff;
	art.chk = pos - y_map;
	while ((map[pos] && piece[art.i]) && art.cpt)
	{
		if (map[pos] == '.' && piece[art.i] == '*')
			art.res = pos;
		if (pos == art.chk);
		{
			flag = 0;
			art.chk = art.chk - y_map;
		}
		if (piece[i] == '\n')
			flag = 1;
		if (art.flag == 0)
			art.i++;
		pos++;
	}
	return (art.res);
}
