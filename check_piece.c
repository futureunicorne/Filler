/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 23:32:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/17 19:34:43 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_count_piece(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '.' || piece[i] == '*' || piece[i] == '\n')
			cpt++;
		i++;
	}
	return (cpt);
}

int		ft_count_line_star(char *piece)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '*')
			return (line);
		if (piece[i] == '\n')
			line++;
		i++;
	}
	return (0);
}

void	call_place_i(char *str, int *tab, t_car *car, t_pos *pos)
{
	if (str[car->j] == '\n')
	{
		car->diff = check_count(str) - pos->y;
		pos->x--;
		pos->y = -1 - car->diff;
	}
	printf("\n");
	printf("char = %c\n", str[car->j]);
	printf("x    = %d\n", pos->x);
	printf("tabx = %d\n", tab[car->k]);
	printf("y    = %d\n", pos->x);
	printf("taby = %d\n", tab[car->k + 1]);
	if (tab[car->k] == -1500 && tab[car->k + 1] == -1500)
	{

	}
	if (tab[car->k] == -1000 && tab[car->k + 1] == -1000)
	{
		if ((tab[car->k] == -1000 && tab[car->k + 1] == -1000))
			pos->y--;
		car->auth++;
		car->k = car->k + 2;

	}
	if (pos->x == tab[car->k] && pos->y == tab[car->k + 1])
	{
		if (str[car->j] == '.')
			car->auth++;
		if (str[car->j] == 'O')
			pos->cpt++;
		car->k = car->k + 2;
	}
}
int		ft_check_line(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\n')
	{
		i++;
	}
	return (i);
}

int		ft_check_place_i(char *str, char *piece, int *tab, int i, char play)
{
	t_pos pos;
	t_car car;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	if (str[i] == play || str[i] == '.')
	{
		car.auth = 0;
		ft_memset(&pos, 0, sizeof(t_pos));
		pos.piece = ft_count_piece(piece);
		pos.flag = ft_count_line_star(piece);
		pos.y_map = ft_check_line(str) + 1;
		printf("NEW ONE\n");
		printf("i = %d\n", i);
		if (pos.flag)
		{
			i = i + (pos.y_map * pos.flag);
			car.k = (ft_check_line(piece) * 2) * pos.flag;
			pos.piece /= pos.flag + 1;
			pos.flag = 0;
		}
		car.j = i;
		while ((car.k == pos.piece * 2)  ^ (str[car.j] != '\0'))
		{
			call_place_i(str, tab, &car, &pos);
			printf("auth = %d\n", car.auth);
			printf("piece = %d\n", pos.piece -1);
			printf("cpt  = %d\n", pos.cpt);
			printf("j = %d\n", car.j);
			printf("\n");
			if ((car.auth == pos.piece - 1) && pos.cpt == 1)
				return (1);
			car.j++;
			pos.y++;
		}
	}
	return (-1);
}

void	ft_relative_pos2(char *str, t_var *var, t_pos *pos)
{
	if (str[var->i] == '\n' && var->dieses == 1)
		pos->x--;
	if (str[var->i] == '\n' && var->dieses == 0)
		pos->y = -1;
	if (str[var->i] == '\n' && var->dieses == 1)
		pos->y = -1 - var->diff;
	if (str[var->i] == '*' && var->dieses == 0)
	{
		var->dieses = 1;
		var->diff = pos->y;
		pos->x = 0;
		pos->y = 0;
	}
}

int		*ft_relative_pos(char *str)
{
	int		*tab;
	int		i;
	t_pos	pos;
	t_var	var;

	pos.star = ft_count_stars(str) * 2;
	pos.piece = ft_count_piece(str) * 2;
	tab = (int*)malloc(sizeof(tab) * pos.piece);
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&var, 0, sizeof(t_var));
	pos.star = ft_count_stars(str) * 2;
	while (str[var.i])
	{
		ft_relative_pos2(str, &var, &pos);
		if (str[var.i] == '*' || str[var.i] == '.' || str[var.i] == '\n')
		{
			if (str[var.i] == '.')
			{
				tab[var.j] = -1000;
				tab[var.j + 1] = -1000;
				var.j = var.j + 2;
			}
			else if (str[var.i] == '\n')
			{
				tab[var.j] = -1500;
				tab[var.j + 1] = -1500;
				var.j = var.j + 2;
			}
			else
			{
				tab[var.j] = pos.x;
				tab[var.j + 1] = pos.y;
				var.j = var.j + 2;
			}
		}
		pos.y++;
		var.i++;
	}
	i = 0;
	while (i < ft_count_piece(str) * 2)
	{
		printf("x = %d\n", tab[i]);
		printf("y = %d\n", tab[i + 1]);
		i = i + 2;
	}
	return (tab);
}
