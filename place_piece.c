/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/17 08:23:09 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_median_class(char *map, char *piece, t_stg *stg, char play)
{
	int f;
	int e;

	f = stg->med_f + 18;
	e = stg->med_e + 18;
	printf("f= %d\n", f);
	printf("e = %d\n", e);
	if (stg->pos >= f && stg->pos <= e)
	{
		if (ft_check_mediane(map, stg->med_f, stg->med_e))
			stg->res = ft_mediane_stg(map, piece, stg->tab, stg->med_f, play);
	}
}

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->e_co, stg->med_e) == 0)
	{
		stg->res = ft_cover_top_place(map, piece, stg->tab, stg->e_co,
		stg->med_e, play);
		if (stg->res == -1)
			stg->res = ft_cover_top_rev(map, piece, stg->tab, stg->e_co,
			stg->med_e, play);
	}
	else if (ft_check_dark_side(stg->e_co, stg->med_e) == 1)
	{
		stg->res = ft_cover_bottom_place(map, piece, stg->tab, stg->pos,
		stg->med_e, play);
		if (stg->res == -1)
			stg->res = ft_cover_bot_rev(map, piece, stg->tab, stg->e_co,
			stg->med_e, play);
	}
}

int	ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.tab = ft_relative_pos(piece);
	stg.pos = ft_start_place(map, play);
	stg.e_co = ft_enemy_start_place(map, play);
	stg.med_f = ((ft_strlen(map) / 2) - ((art->x_map / 2) + 2));
	stg.med_e = ((ft_strlen(map) / 2) - ((art->x_map / 2) + 2)) + art->y_map -1;
	printf("pos = %d\n", stg.pos);
	printf("med_f= %d\n", stg.med_f);
	printf("med_e = %d\n", stg.med_e);
	ft_median_class(map, piece, &stg, play);
	ft_strategy_attack(map, piece, &stg, play);
	if (stg.res == -1)
		stg.res = ft_place_anywhere(map, piece, stg.tab, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
