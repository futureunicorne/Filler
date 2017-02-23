/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:32:02 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/23 09:37:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

premiere condition :
if dark_side

if (ft_over_pass == 0)

	ft_cover_bottom_place opti
	ft_check_mediane opti par rapport au back slash
	ft_attack_position2 opti
	ft_check_field
	if 1
		ft_cover_From_end
	if 	0
		ft_cover from_start
if (ft_over_pass = 1)
 	ft_follow_enemy
	if check_tiers == 1
		ft_place from median to the topE

else if dark side

int		ft_over_pass(char *map, char *piece, char play, char play2)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (pos.i >= 0 && map[pos.i] != play)
		pos.i--;
	while (map[pos.j] && map[pos.j] != play2)
		pos.j++;
	if (pos.i > pos.j) // O superieur donc over_pass donc 1
		return (1);
	return (0);
}

int	ft_cover_bottom_place(char *map, char *piece, int e_co, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = e_co;
	while (map[pos.i])
	{
		if (ft_control_check(map, piece, pos.i, play))
			return (pos.i);
		pos.i++;
	}
	return (-1);
}

int		ft_median_point(char *map)
{
	int i;
	int line;
	int cpt;

	i = 0;
	line = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			line++;
		i++;
	}
	line = line / 2;
	i = 0;
	cpt = 0;
	while (map[i] && cpt < line)
		i++;
	return (i);
}

int		ft_check_mediane(char *map, char *piece, char play)
{
	t_pos pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.i = ft_mediane_point(map);
	while (map[i] != '\n')
	{
		if (map[i] == 'O')
			return (1);
		i--;
	}
	return (0);
}

int		ft_follow_enemy(char *map, char *piece, char play)
{

}