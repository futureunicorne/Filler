/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:26:09 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 15:27:41 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_check_place(char *map, char *piece, char play)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	piece = NULL;
	while (map[art.i] != play)
		art.i++;
	printf("%d\n", art.i);
	return (art.i);
}
/*
int		*ft_middle_strategy(char *map, char *piece, )
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));

}
*/
