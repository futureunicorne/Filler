/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stg_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:53:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 16:55:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_nbr_line(char *map)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			cpt++;
		i++;
	}
	return (cpt);
}


int		ft_end_line(char *map, char play)
{
	int i;

	i = ft_strlen(map);
	while (i >= 0 &&  map[i] != play)
	{
		i--;
	}
	while (map[i] != '\n')
		i++;
	return (i);
}

int		ft_check_half_line(char *map)
{
	int cpt;
	int i;

	i = 0;
	cpt = 0;
	while (map[i] != '\n')
	{
		i++;
		cpt++;
	}
	return (cpt);
}

int		ft_check_half_map(char *map)
{
	int i;
	int cpt;
	int auth;

	cpt = ft_nbr_line(map) / 2;
	i = 0;
	auth = 0;
	while (auth < cpt)
	{
		if (map[i] == '\n')
			auth++;;
		i++;
	}
	return (i);
}
