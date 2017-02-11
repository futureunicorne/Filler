/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:40:50 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 17:18:50 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_map_lengt(char *map, int x_map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	return (i - x_map);
}

int		*ft_middle_strategy(char *map, piece, char play, char play2)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	


}
