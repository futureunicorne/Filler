/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:18:56 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 17:21:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(void)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	ref.fd = 0;
	ref.play = ft_record_playnbr(ref.fd);
	if (!ref.play)
	{
		ft_putstr_fd("Bad player info\n", 2);
		return (0);
	}
	while (100)
	{
		ref.tab = ft_record_size_map(ref.fd);
		ref.x = ref.tab[0];
		ref.y = ref.tab[1];
		ref.map = ft_record_map(ref.x, ref.fd);
		ref.tab2 = ft_record_size_piece(ref.fd);
		ref.xp = ref.tab2[0];
		ref.piece = ft_record_piece(ref.xp, ref.fd);
		if (ft_check_battle(ref.map, ref.piece, ref.play, ref.x, ref.y) == 0)
			break ;

	}
	return (0);
}
