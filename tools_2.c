/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/14 18:23:09 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_check_nbrline(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\n')
		i++;
	return (i);
}

int	ft_check_diff(char *piece, int i)
{
	int j;

	j = i;
	while (piece[j])
		j++;
	return (j);
}
