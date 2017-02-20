/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:14:24 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/20 18:27:11 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/test.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (c >= 0 || c <= 127)
	{
		s1 = (char*)s;
		while (i < n)
		{
			s1[i] = c;
			i++;
		}
	}
	return (s);
}

int		ft_check_tiers(char *map)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	printf("%s\n",map);
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			cpt++;
		i++;
	}
	printf("MAP = %d\n", cpt);
	return (cpt);
}


int	main(void)
{
	char *str;

	str = ".................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n.................\n";
 	ft_check_tiers(str);
	return (0);
}
