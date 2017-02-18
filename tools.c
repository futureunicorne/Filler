/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:49:55 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 15:43:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	ft_record_playnbr(int fd)
{

	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	get_next_line(fd, &ref.line1);
	printf("joueur = %s\n", ref.line1);
	ref.nb = ft_atoi(ref.line1 + 10);
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
	if ((ref.tab = (int*)malloc(sizeof(int) * 3)) == 0)
		return (0);
	get_next_line(fd, &ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 8);
	ref.tab[1] = ft_atoi(ref.line1 + 10);
	printf("plateau x = %d\n", ref.tab[0]);
	printf("plateau y = %d\n", ref.tab[1]);
	return (ref.tab);
}

int		*ft_record_size_piece(int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	if ((ref.tab = (int*)malloc(sizeof(int) * 3)) == 0)
		return (0);
	get_next_line(fd, &ref.line1);
	printf("sizep = %s\n", ref.line1);
	ref.tab[0] = ft_atoi(ref.line1 + 6);
	ref.tab[1] = ft_atoi(ref.line1 + 8);
	printf("xp = %d\n", ref.tab[0]);
	printf("xy = %d\n", ref.tab[1]);
	return (ref.tab);
}

char	*ft_record_map(int lgt, int fd)
{
	t_ply ref;

	ft_memset(&ref, 0, sizeof(t_ply));
	get_next_line(fd, &ref.line1);
	printf("nul = %s\n", ref.line1);
	ref.map = "";
	while (ref.i < lgt)
	{
		get_next_line(fd, &ref.line1);
		ref.map = ft_strjoin(ref.map, ref.line1 + 4);
		ref.map = ft_strjoin(ref.map, "\n");
		ref.i++;
	}
	printf("map = \n%s\n", ref.map);

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
		ref.map = ft_strjoin(ref.map, ref.line1);
		ref.map = ft_strjoin(ref.map, "\n");
		ref.i++;
	}
	printf("piece = \n%s", ref.map);
	return (ref.map);
}
