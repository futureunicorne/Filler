/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:18:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/15 17:10:26 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_ply  // separer structure trop longue
{
	int		fd;
	int 	flag;
	int 	nb;
	int		i;
	int		x;
	int		y;
	int		xp;
	int		yp;
	char	play;
	char 	*line1;
	int		*tab;
	int		*tab2;
	char	*map;
	char	*piece;
}				t_ply;

typedef struct	s_art
{
	int		max;
	int 	min;
	int		i;
	int		j;
	int		x;
	int		y;
	int		x_map;
	int		y_map;
	int		pos;
	int		cpt;
	int		pos_ad;
	int		diff;
	char	play2;
	char	*res;
}				t_art;

typedef	struct		s_pos
{
	int				x;
	int				y;
	int				i;
	int				cpt;
	int				star;
	int				place;
}					t_pos;

typedef	struct		s_var
{
	int				i;
	int				j;
	int				diff;
	int				dieses;
	t_list			*elem;
	t_list			*mat;
}					t_var;

typedef	struct		s_car
{
	char			*dst;
	int				i;
	int				j;
	int				k;
	int				flag;
	int				diff;
	int				auth;
}					t_car;

char				ft_record_playnbr(int fd);
int					*ft_record_size_map(int fd);
int					*ft_record_size_piece(int fd);
char				*ft_record_map(int lgt, int fd);
char				*ft_record_piece(int lgt, int fd);
int					ft_check_battle(char *map, char *piece, char play, int x_map, int y_map);
char				ft_enemy_letter(int play);
int					ft_enemy_start_place(char *map, char play2);
int					ft_start_place(char *map, char play);
int					*ft_relative_pos(char *str);
void				ft_relative_pos2(char *str, t_var *var, t_pos *pos);
int					ft_check_place_i(char *str, char *piece, int *tab, int i, char play);
void				call_place_i(char *str, int *tab, t_car *car, t_pos *pos);
int					ft_place_piece(char *map, char *piece, char play, t_art *art);
int					ft_optimal_check(char *map, char play, int flag, t_art *art);
int					ft_convert_x(char *map, int conv);
int					ft_convert_y(char *map, int conv);
int					ft_count_stars(char *piece);
int					check_count(char *str);
int					record_left_corner(char *piece);


char	*ft_place_i(char *str, char *piece, int *tab, int i);
void	call_place(char *str, int *tab, t_car *car, t_pos *pos);









#endif
