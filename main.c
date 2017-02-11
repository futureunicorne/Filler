/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 07:42:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int	main(void)
{
	int		fd;
	int 	i;
	char	*line1;
	char	*line2;
	char	*map;


	fd = 0;
	i = 0;
	get_next_line(fd, &line1); // recuperation du nom de joueur et de la place
	printf("%s\n", line1);
	get_next_line(fd, &line2);  // recuperation de la taille de la map
	printf("%s\n", line2);
	while (1)
	{
		get_next_line(fd, &line)
		// recuperation de la map
		// recupperation de la piece
		// algo min max
		if (ft_check_strategy(map) == 0 && flag == 0)
			ft_basic_algo(map, piece);
		else if (ft_check_strategy(map) && flag == 0)
			ft_min_max(map, piece);
		i++;
	}
	return (0);
}
