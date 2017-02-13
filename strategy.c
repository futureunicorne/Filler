/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:40:50 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 06:59:22 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_map_length(char *map, int x_map)
{
	int i;
	int	res;

	i = 0;
	while (map[i] != '\0')
		i++;
	res =  i - x_map;
	return (res);
}

int		*ft_middle_strategy(char *map, piece, char play, x_ma )
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	return (0);
}
