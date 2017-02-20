/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:32:02 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 16:07:40 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strategy_attack(char *map, char *piece, t_stg *stg, char play)
{
	if (ft_check_dark_side(stg->e_co, stg->pos) == 1) // si en dessous
	{
		stg->res = ft_cover_bottom_place(map, piece, stg->pos, play);
		if (stg->res == -1)
			stg->res = ft_cover_bot_rev(map, piece, stg->e_co,
			stg->med_e, play);
	}
	else if (ft_check_dark_side(stg->e_co, stg->pos) == 0)
	{
		stg->res = ft_cover_top_place(map, piece, stg->e_co,
		stg->med_e, play);
		if (stg->res == -1)
			stg->res = ft_cover_top_rev(map, piece, stg->e_co,
			stg->med_e, play);
	}

}


int	ft_cover_top_place(char *map, char *piece, int place, int med_e, int play)
{
	int i;

	i = place;
	while (i <= med_e)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i++;
	}
	i = place;
	while (i >= 0)
	{
		if (ft_control_check(map, piece, i, play) == 1)
			return (i);
		i--;
	}
	return (-1);
}
