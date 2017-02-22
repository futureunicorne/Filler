/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:55:25 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 16:55:38 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_bound(char *map, int flag)
{
	int cpt;
	int auth;
	int i;


	i = 0;
	auth = 0;
	cpt = ft_nbr_line(map) / 2;
	if (flag == 0)
	{
		i = 0;
		while (map[i] && auth < cpt)
		{
			if (map[i] == '\n')
				auth++;
			i++;
		}
	}
	else if (flag == 1)
	{
		i = ft_strlen(map);
		while (i >= 0 && auth < cpt + 1)
		{
			if (map[i] == '\n')
				auth++;
		 	i--;
		}
	}
	return (i - 1);
}

int	ft_check_tiers(char *map, int flag, char play)
{
	int i;
	int cpt;

	cpt = ft_check_bound(map, flag);
	if (flag == 0)
	{
		i = 0;

		while (i < cpt)
		{
			if (map[i] == play)
				return (1);
			i++;
		}
	}
	if (flag == 1)
	{
		i = ft_strlen(map);
		while (i > cpt)
		{
			if (map[i] == play)
				return (1);
			i--;
		}
	}
	return (0);
}

int 	ft_check_position(char *map, int med_f)
{
	int i;
	int pts;
	int res;

	i = 0;
	pts = 0;
	while (i <= med_f)
	{
		if (map[i] == '.')
			pts++;
		i++;
	}
	res = (med_f / 10) * 2;
	if (pts > res)
		return (1);
	return (0);
}
