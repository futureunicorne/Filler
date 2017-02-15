/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 11:27:19 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(int argc, char **argv)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	ref.fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		ref.play = ft_record_playnbr(ref.fd);
		printf("char = %c\n", ref.play);
		ref.tab = ft_record_size_map(ref.fd);
		ref.x = ref.tab[0];
		ref.y = ref.tab[1];
		printf("x = %d\n", ref.x);
		printf("y = %d\n", ref.y);
		free(ref.tab);
		while (100)
		{
			ref.map = ft_record_map(ref.x, ref.fd);
			printf("map \n%s\n", ref.map);
			ref.tab = ft_record_size_piece(ref.fd);
			ref.xp = ref.tab[0];
			printf("xp  = %d\n", ref.xp);
			free(ref.tab);
			ref.piece = ft_record_piece(ref.xp, ref.fd);
			printf("piece = \n%s\n", ref.piece);
			if (ft_check_battle(ref.map, ref.piece, ref.play, ref.x, ref.y) == 0)
				break ;
			break;
		}
	}
	return (0);
}
