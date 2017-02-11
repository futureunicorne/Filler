/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:49:55 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/11 15:38:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	ft_record_playnbr(void)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	get_next_line(ref.fd, &ref.line1);
	ref.nb = ft_atoi(ref.line1 + 10);
	if (ref.nb == 1)
		return ('O');
	else if (ref.nb == 2)
		return ('X');
	return (0);
}

int		*ft_record_size_map(void)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if ((ref.tab = (int*)malloc(sizeof(int) * 3)) == 0)
		return (0);
	get_next_line(ref.fd, &ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 8);
	ref.tab[1] = ft_atoi(ref.line1 + 10);
	return (ref.tab);
}

int		*ft_record_size_piece(void)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if ((ref.tab = (int*)malloc(sizeof(int) * 3)) == 0)
		return (0);
	get_next_line(ref.fd, &ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 6);
	ref.tab[1] = ft_atoi(ref.line1 + 8);
	return (ref.tab);
}

char	*ft_record_map(int lgt)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	while (ref.i < 3)
	{
		get_next_line(ref.fd, &ref.line1);
		ref.i++;
	}
	ref.i = 0;
	ref.map = "";
	while (ref.i < lgt)
	{
		get_next_line(ref.fd, &ref.line1);
		ref.map = ft_strjoin(ref.map, ref.line1);
		ref.map = ft_strjoin(ref.map, "\n");
		ref.i++;
	}
	return (ref.map);
}

char	*ft_record_piece(int lgt)
{
	t_ply	ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	ref.map = "";
	while (ref.i < lgt)
	{
		get_next_line(ref.fd, &ref.line1);
		ref.map = ft_strjoin(ref.map, ref.line1);
		ref.map = ft_strjoin(ref.map, "\n");
		ref.i++;
	}
	return (ref.map);
}
