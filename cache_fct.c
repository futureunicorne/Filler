/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 10:17:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 15:13:04 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_free_full_place(char *map, char *piece, int i)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	while (piece[art.i])
	{
		if (piece[art.i] == '*' && map[art.i] != '.')
			return (0);
		art.i++;
	}
	return (1);
}


int	ft_check_piece_place(char *map, char *piece)
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	i = ft_optimal_position(map, piece, play);
	art.med =  (ft_strlen(map) / 2) + y_map - x_map
	if (art.i > art.med)
		ft_place_high(map, piece, art.i);
	else if (art.i < art.med)
		ft_place_low(map, piece, art.i);
	else if (art.i >= art.med && art.i <= art.med - y_map)
		ft_close_line(map, piece, art.i)
	while (map[art.i])
	{
		if (ft_free_point(map, piece, art.i))
		{
			if (ft_free_full_place(map, piece, art.i))
				return (i);
		}
		art.i++;
	}
	return (0);
}

int	ft_free_point(char *map, char *piece, int i)
{
	while(map[i])
	{
		if (map[i] == '.')
			return (1);
		i++;
	}
	return (-1);
}

int		ft_map_length(char *map, int x_map)
{
	int i;
	int	res;

	i = 0;
	while (map[i] != '\0')
		i++;
	res =  i - x_map;
	return (res);
}

int		*ft_middle_strategy(char *map, piece, char play, x_ma )
{
	t_art art;

	ft_memset(&art, 0, sizeof(t_art));
	return (0);
}
