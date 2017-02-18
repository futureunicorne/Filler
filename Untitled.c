/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:32:02 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/18 17:41:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_reduct(char *piece, int i)
{
	int flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	if (piece[i] == '*')
		return (0);
	while (piece[i] != '\n')
	{
		if (piece[i] == '.')
			flag = 1;
		if (piece[i] == '*')
		i++;
	}
	if (flag && flag2)
		return (1);
	return (0);
}

char 	*ft_reduct_piece(char *piece)
{
	t_pos pos;

	ft_memset(&pos, 0, t_pos);
	lgt = ft_record_lgt(piece);
	wdt = ft_record_wdt(piece);

	while (piece[i])
	{
		if (piece[i] == '*')
		{
			dst[j] = '*';
			j++;
			if (check_reduct(piece, i + 1))
				flag = 1;
		}
		if (flag == 1 && piece[i] == '.')
		{
			dst[j] = '*';
			j++;
		}
		if (piece[i] == '*' && flag == 1)
			flag = 0;
		if (piece[i] == '\n')
		{
			dst[j] = '*';
			j++;
		}
		i++;
	}
	return (dst)
}

int		ckeck_place_star(char *str, char *piece, int i, char play)
{
	int j;
	int k;
	int l;
	t_pos pos;

	j = 0;
	k = i;
	l = 0;
	ft_memset(&pos, 0, sizeof(pos));
	pos.flag2 = i;
	pos.star = ft_count_stars2(piece);
	while (l < k)
	{
		if (str[l] == '\n')
			pos.flag = 0;
		l++;
		pos.flag++;
	}

	printf("res ====== %d\n", ft_check_line(str));
	printf("flag ====== %d\n", pos.flag2);
	while (piece[j] && str[i])
	{
		printf("NEWW BOUCLE\n\n");
		printf("chari = %c\n", str[i]);
		printf("leni = %d\n", i);
		printf("charj = %c\n", piece[j]);
		printf("lenj = %d\n", j);
		if (str[i] == '.' && piece[j] == '*')
			pos.auth++;
		if (str[i] == play && piece[j] == '*')
			pos.cpt++;
		printf("cpt   =%d\n", pos.cpt);
		printf("auth  =%d\n", pos.auth);
		if (i == (ft_check_line(str) + pos.flag2) - 1)
			j++;
		if ((piece[j] != '\n'|| (piece[j] == '\n' && piece[j + 1] == '\0')) &&
		(i != (ft_check_line(str) + pos.flag2) - 1))
			j++;
		i++;

	}
	printf("cpt   =%d\n", pos.cpt);
	printf("auth  =%d\n", pos.auth);
	if (pos.cpt == 1 && pos.auth == pos.star - 1)
		return (1);
	return (0);
}
