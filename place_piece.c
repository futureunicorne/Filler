/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:18:58 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/21 17:50:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_nbr_line(char *map)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			cpt++;
		i++;
	}
	return (cpt);
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

int		ft_check_half_line(char *map)
{
	int cpt;
	int i;

	i = 0;
	cpt = 0;
	while (map[i] != '\n')
	{
		i++;
		cpt++;
	}
	return (cpt);
}

int		ft_check_half_map(char *map)
{
	int i;
	int cpt;
	int auth;

	cpt = ft_nbr_line(map) / 2;
	i = 0;
	auth = 0;
	while (auth < cpt)
	{
		if (map[i] == '\n')
			auth++;;
		i++;
	}
	return (i);
}

int		ft_restart_line(char *map, int pos)
{
	int i;
	int res;
	int diff;

	i = pos;
	diff = ft_check_half_line(map);
	while (map[i] != '\n' && i >= 0)
	{
		i--;
	}
	res = i - diff;
	return (i);
}

int 	ft_re_align_left(char *map, char *piece, int pos, char play)
{
	int i;
	int align;

	i = pos;
	align = ft_restart_line(map, pos);
	while (i >= align)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_attack_special_part3(char *map, char *piece, int pos, char play) // du bas a droit vers le haut
{
	int i;
	int chk;
	int diff;
	int half;

	half = ft_check_half_line(map) / 3;
	diff = ft_check_half_line(map) - half - 10;
	dprintf(2, "HAAAAAAUUUUUUUUUUUUUUUUUT ======== %d\n", diff);
	i = ft_strlen(map);
	pos = 0;
	while (i >= 0)
	{
		if (map[i] == '\n')
			chk = -1 - diff;
		if (chk >= half)
		{
			if (ft_control_check(map, piece, i, play) == 1)
				return (i);
		}
		i--;
		chk++;
	}
	return (-1);
}

int		ft_attack_special(char *map, char *piece, int e_co, char play)
{
	int i;
	int chk;
	int half;

	half = ft_check_half_line(map) / 2;
	i = ft_strlen(map);
	e_co = 0;
	while (i >= 0)
	{
		if (map[i] == '\n')
			chk = -1;
		if (chk >= half)
		{
			if (ft_control_check(map, piece, i, play) == 1)
				return (i);
		}
		i--;
		chk++;
	}
	return (-1);
}

int		ft_attack_special_part2(char *map, char *piece, int pos, char play)
{
	//int i;
	int half;

	half = ft_check_half_map(map) - ft_check_half_line(map) + 1 + 41;
	dprintf(2, "================================================= CHECK = %d\n", half);
	while (half < pos)
	{
		if (ft_control_check(map, piece, half, play) == 1)
			return (half);
		half++;
	}
	return (-1);
}

int		ft_cover_my_position(char *map, char *piece, int pos, char play)
{
	int i;

	i = ft_strlen(map);
	while (i >= pos)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	i = ft_re_align_left(map, piece, pos, play);
	if (i)
		return (i);
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


int		ft_check_bound(char *map, int flag)
{
	int cpt;
	int auth;
	int i;


	i = 0;
	auth = 0;
	cpt = ft_nbr_line(map) / 5;
	if (flag == 0)
	{
		i = 0;
		while (map[i] && auth < cpt)
		{
			if (map[i] == '\n')
				auth++;
			i++;
		}
	}
	else if (flag == 1)
	{
		i = ft_strlen(map);
		while (i >= 0 && auth < cpt + 1)
		{
			if (map[i] == '\n')
				auth++;
		 	i--;
		}
	}
	printf(" res ligne %i\n", i - 1);
	return (i - 1);
}

int	ft_check_tiers(char *map, int flag, char play)
{
	int i;
	int cpt;

	cpt = ft_check_bound(map, flag);
	if (flag == 0)
	{
		i = 0;
		//dprintf(2, "RESULTAT =================================   %d ================================= \n", cpt);

		while (i < cpt)
		{
			if (map[i] == play)
				return (1);
			i++;
		}
	}
	if (flag == 1)
	{
		i = ft_strlen(map);
		while (i > cpt)
		{
			if (map[i] == play)
				return (1);
			i--;
		}
	}
	return (0);
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

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	/*
	if (ft_check_dark_side(stg->pos, stg->e_co) == 1)
	{
		if (ft_check_tiers(map, 1, play) == 0)
			stg->res = ft_cover_bottom_place(map, piece, stg->med_f, play);
		else
			stg->res =  ft_attack_position(map, piece, stg->e_co, play);
	}
	if (ft_check_dark_side(stg->pos, stg->e_co) == 0)
	{
		if (ft_check_tiers(map, 0, play) == 0)
			stg->res =ft_attack_special_part3(map, piece, stg->pos, play);
		if (ft_check_tiers(map, 0, play) == 1)
		{
			stg->res =  ft_attack_position(map, piece, stg->e_co, play);
		}
	}
	*/


	//stg->res =  ft_re_align_left(map, piece, stg->pos, play);
	stg->res = ft_attack_special_part3(map, piece, stg->pos, play);
	if (stg->res == - 1)
		stg->res = ft_attack_special_part3(map, piece, stg->pos, play);
	if (stg->res == - 1)
		stg->res = ft_attack_position(map, piece, stg->e_co, play);
}

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
