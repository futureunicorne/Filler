/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:49:55 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/03 08:54:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	ft_record_playnbr(int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	get_next_line(fd, &ref.line1);
	ref.nb = ft_atoi(ref.line1 + 10);
	free (ref.line1);
	if (ref.nb == 1)
		return ('O');
	else if (ref.nb == 2)
		return ('X');
	return (0);
}

int		*ft_record_size_map(int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if (!(ref.tab = (int *)malloc((3) * sizeof(int))))
		return (0);
	get_next_line(fd, &ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 8);
	ref.tab[1] = ft_atoi(ref.line1 + 10);
	free (ref.line1);
	return (ref.tab);
}

int		*ft_record_size_piece(int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if (!(ref.tab = (int *)malloc((3) * sizeof(int))))
		return (0);
	get_next_line(fd, &ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 6);
	ref.tab[1] = ft_atoi(ref.line1 + 8);
	free (ref.line1);
	return (ref.tab);
}

char	*ft_record_map(int lgt, int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	get_next_line(fd, &ref.line1);
	free (ref.line1);
	ref.map = "";
	while (ref.i < lgt)
	{
		get_next_line(fd, &ref.line1);
		ref.map3 = ft_strdup(ref.line1);
		if (ft_strlen(ref.line1) != 0)
			free (ref.line1);
		ref.map2 = ft_strdup(ref.map);
		if (ft_strlen(ref.map) != 0)
			free (ref.map);
		ref.map = ft_strjoin_b(ref.map2, ref.map3 + 4);
		if (ft_strlen(ref.map2) != 0)
			free (ref.map2);
		if (ft_strlen(ref.map3) != 0)
			free (ref.map3);
		ref.i++;
	}
	return (ref.map);
}

char	*ft_record_piece(int lgt, int fd)
{
	t_ply	ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	ref.map = "";
	while (ref.i < lgt)
	{
		get_next_line(fd, &ref.line1);
		ref.map3 = ft_strdup(ref.line1);
		if (ft_strlen(ref.line1) != 0)
			free (ref.line1);
		ref.map2 = ft_strdup(ref.map);
		if (ft_strlen(ref.map) != 0)
			free (ref.map);
		ref.map = ft_strjoin_b(ref.map2, ref.map3);
		if (ft_strlen(ref.map2) != 0)
			free (ref.map2);
		if (ft_strlen(ref.map3) != 0)
			free (ref.map3);
		ref.i++;
	}
	return (ref.map);
}
