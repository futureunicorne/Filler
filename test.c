#include <stdio.h>
#include <stdlib.h>
#include "test.h"
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

int	ft_count_stars(char *piece)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '*')
			cpt++;
		i++;
	}
	return (cpt);
}
int				check_count(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

static void	call_place_i(char *str, int *tab, t_car *car, t_pos *pos)
{
	if (str[car->j] == '\n')
	{
		car->diff = check_count(str) - pos->y;
		pos->x--;
		pos->y = -1 - car->diff;
	}
	if (pos->x == tab[car->k] && pos->y == tab[car->k + 1])
	{
		if (str[car->j] == '.')
			car->auth++;
		car->k = car->k + 2;
	}
}

int			ft_check_place_i(char *str, char *piece, int *tab, int i)
{
	t_pos pos;
	t_car car;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&car, 0, sizeof(t_car));
	pos.star = ft_count_stars(str);
	if (str[i] == '*' )
	{
		car.auth = 0;
		ft_memset(&pos, 0, sizeof(t_pos));
		pos.star = ft_count_stars(piece);

		car.j = i;
		car.k = 0;
		while (str[car.j] ^ (car.k == pos.star * 2))
		{
			call_place_i(str, tab, &car, &pos);
			if (car.auth == pos.star - 1)
			{
				return (1);
			}
			car.j++;
			pos.y++;
		}
	}
	return (0);
}

void		ft_relative_pos2(char *str, t_var *var, t_pos *pos)
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
	tab = (int*)malloc(sizeof(tab) * pos.star);
	ft_memset(&pos, 0, sizeof(t_pos));
	ft_memset(&var, 0, sizeof(t_var));
	pos.star = ft_count_stars(str) * 2;
	while (str[var.i])
	{
		ft_relative_pos2(str, &var, &pos);
		if (str[var.i] == '*')
		{
			tab[var.j] = pos.x;
			tab[var.j + 1] = pos.y;
			var.j = var.j + 2;
		}
		pos.y++;
		var.i++;
	}
	i = 0;
	while (i < pos.star)
	{
		printf("x = %d ", tab[i]);
		printf("y = %d\n", tab[i + 1]);
		i = i + 2;
	}
	return (tab);
}

int	main(void)
{
	char *str;
	char *str1;
	int *tab;

	str = ".*.\n***\n.*.\n";
	tab = ft_relative_pos(str);
	str1 = "...........\n.....*.....\n...*......\n...........\n...........\n";
	printf("res = %d\n", ft_check_place_i(str1, str,tab, 17));
	return (0);
}
