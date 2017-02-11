/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 15:38:21 by hel-hadi         ###   ########.fr       */
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
		ref.play = ft_record_playnbr(fd);
		ref.tab = ft_record_size_map(fd);
		ref.x = ref.tab[0];
		ref.y = ref.tab[1];
		free(ref.tab);
		while (100)
		{
			ref.map = ft_record_map(ref.x, fd);
			ref.tab = ft_record_size_piece(fd);
			ref.xp = ref.tab[0];
			free(ref.tab);
			ref.piece = ft_record_piece(ref.xp, fd);
			ft_check_place(ref.map, ref.piece, ref.play);
			break ;
		}
	}
	return (0);
}
