/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cache_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 08:57:17 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 09:15:43 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_place_anywhere(char *map, char *piece, char play)
{
	t_art art;

	t_art art;
	ft_memset(&art, 0, sizeof(t_art));
	i = ft_start_place(map, piece, play);
	while (map[art.i])
	{
		if (ft_check_place(map, piece, art.i) == 1)
			return (art.i);
		art.i++;
	}
	return (-1);
}

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
