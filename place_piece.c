/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 17:53:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_median_class(char *map, char *piece, t_stg *stg, char play)
{
	int f;
	int e;

	f = stg->med_f + 18;
	e = stg->med_e + 18;
	if (stg->pos >= f && stg->pos <= e)
	{
		if (ft_check_mediane(map, stg->med_f, stg->med_e))
			stg->res = ft_mediane_stg(map, piece, stg->med_f, play);
	}
}

int		ft_end_line(char *map, char play)
{
	int i;

	i = ft_strlen(map);
	while (i >= 0  &&  map[i] != play)
	{
		i--;
	}
	while (map[i] != '\n')
		i++;
	return (i);
}

int		ft_cover_my_position(char *map, char *piece, t_stg *stg, char play)
{
	int i;

	i = stg->med_e;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_attack_position(char *map, char *piece, int e_co, char play)
{
	int i;

	i = e_co;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	i = e_co;
	while (map[i])
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int 	ft_check_position(char *map, int med_f)
{
	int i;
	int pts;
	int res;

	i = 0;
	pts = 0;
	while (i <= med_f)
	{
		if (map[i] == '.')
			pts++;
		i++;
	}
	res = (med_f / 10) * 2;
	if (pts > res)
		return (1);
	return (0);
}

int		ft_check_tiers

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		if (stg->e_co > ft_start_place(map, play))
			stg->res = ft_cover_bottom_place(map, piece, stg->med_f, play);
		else
			stg->res =  ft_attack_position(map, piece, stg->e_co, play);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		dprintf(2, "WAHOUUUUUUUUUU ================== %d\n", ft_start_place(map, play));

		if (stg->e_co > ft_start_place(map, play))
			stg->res = ft_cover_top_place(map, piece, stg->med_f, play);
		else
		{
			dprintf(2, "NOOOOOOOOOOOOOOOOOOOONNN  ================== \n");
			stg->res =  ft_attack_position(map, piece, stg->e_co, play);
		}
	}
	//stg->res = ft_attack_position(map, piece, stg->e_co, play);

	if (stg->res == - 1)
		stg->res = ft_place_anywhere(map, piece, play);
}

/*
int	ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	int i;
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.pos = ft_start_place(map, play);
	stg.e_co = ft_enemy_start_place(map, play);
	if (art == NULL)
		return (0);
	i = stg.e_co;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	i = stg.e_co;
	while (map[i])
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	return (-1);
}
*/

int	ft_place_piece(char *map, char *piece, char play, t_art *art)
{
	t_stg stg;

	ft_memset(&stg, 0, sizeof(t_stg));
	stg.pos = art->start;
	stg.e_co = art->e_co;
	stg.med_f = ((ft_strlen(map) / 2) - ((art->x_map / 2) + 2));
	stg.med_e = ((ft_strlen(map) / 2) - ((art->x_map / 2) + art->y_map));
	//ft_median_class(map, piece, &stg, play);
	ft_strategy_attack(map, piece, &stg, play);
	if (stg.res >= 0)
		return (stg.res);
	return (-1);
}
