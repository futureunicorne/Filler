/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:32:02 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 11:38:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ckeck_place_piece(char *str, char *piece, int i)
{
	int i;
	t_pos pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(pos));
	while (str[i] && piece[i])
	{
		if (piece[j] != '\n')
			j++;
		if (str[i] == '\n')
			pos.flag2 = -1;
		if (str[i] == '.' && piece[j] == '*')
			pos.auth++;
		if (str[i] == 'O' && piece[j] == '*')
			pos.cpt++;
		i++;
	}
	if (pos.cpt == 1 && pos.auth == 1)
		return (1);
	return (0);
}
