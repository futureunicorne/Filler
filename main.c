/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 15:59:49 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(int argc, char **argv)
{
	t_ply ref;
	int flag;

	ft_memset(&ref, 0, sizeof(t_ply));
	flag = 0;
	if (argc == 2)
	{
		ref.fd = open(argv[1], O_RDONLY);
		ref.play = ft_record_playnbr(ref.fd);
		if (!ref.play)
		{
			ft_putstr_fd("Bad player info\n", 1);
			return (0);
		}
		while (ref.i < 1)
		{
			ref.tab = ft_record_size_map(ref.fd);
			ref.x = ref.tab[0];
			ref.y = ref.tab[1];
			ref.map = ft_record_map(ref.x, ref.fd);
			ref.tab2 = ft_record_size_piece(ref.fd);
			ref.xp = ref.tab2[0];
			ref.piece = ft_record_piece(ref.xp, ref.fd);
			if (flag == 0)
			{
				ref.start = ft_start_place(ref.map, ref.play);
				ref.e_co = ft_enemy_start_place(ref.map, ref.play);
				flag = 1;
			}
			if (ft_check_battle(&ref) == 0)
				break;
			ref.i++;
		}
	}
	return (0);
}
