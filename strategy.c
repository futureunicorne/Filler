/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:40:50 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 16:40:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

{
	int		pos;
	int		index;
	char	tmp[ft_strlen(str)];

	pos = 0;
	index = 0;
	if (!str || !*str)
		return (str);
	while (str[index] != '\0')
	{
		tmp[index] = str[index];
		++index;
	}
	pos = index - 1;
	index = 0;
	while (index != pos + 1)
	{
		str[index] = tmp[pos - index];
		++index;
	}
	return (str);
