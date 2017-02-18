/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 14:25:34 by hel-hadi         ###   ########.fr       */
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
	while (l < k)
	{
		if (str[l] == '\n')
			pos.flag = 0;
		l++;
		pos.flag++;
	}
	while (piece[j] && str[i])
	{
		printf("chari = %c\n", str[i]);
		printf("charj = %c\n", piece[j]);
		printf("len = %d\n", i);
		printf("len = %d\n", j);
		if (str[i] == '.' && piece[j] == '*')
			pos.auth++;
		if (str[i] == play && piece[j] == '*')
			pos.cpt++;
		if (i == (ft_check_line(str) + pos.flag2))
			j++;
		if (piece[j] != '\n')
			j++;
		i++;
	}
	printf("cpt   =%d\n", pos.cpt);
	printf("auth  =%d\n", pos.auth);
	if (pos.cpt == 1 && pos.auth == pos.star - 1)
		return (1);
	return (0);
}
