/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:18:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/22 16:56:14 by hel-hadi         ###   ########.fr       */
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
	int		start;
	int		e_co;
}				t_ply;

typedef struct	s_art
{
	int		max;
	int 	min;
	int		i;
	int		j;
	int		start;
	int		e_co;
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
	int				j;
	int				cpt;
	int				star;
	int				place;
	int				flag;
	int				piece;
	int				y_map;
	int				check;
	int				flag2;
	int				auth;
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

typedef struct		s_stg
{
	int 			i;
	int				pos;
	int 			res;
	int 			med_f;
	int				med_e;
	int				e_co;
	int				*tab;
	int				play2;
}					t_stg;

char				ft_record_playnbr(int fd);
int					*ft_record_size_map(int fd);
int					*ft_record_size_piece(int fd);
char				*ft_record_map(int lgt, int fd);
char				*ft_record_piece(int lgt, int fd);
int					ft_check_battle(t_ply *ref);
char				ft_enemy_letter(int play);
int					ft_enemy_start_place(char *map, char play2);
int					ft_start_place(char *map, char play);
int					*ft_relative_pos(char *str);
void				ft_relative_pos2(char *str, t_var *var, t_pos *pos);
int					ft_place_piece(char *map, char *piece, char play, t_art *art);
int					ft_optimal_check(char *map, char play, int flag, t_art *art);
int					ft_convert_x(char *map, int conv);
int					ft_convert_y(char *map, int conv);
int					ft_count_stars(char *piece);
int					check_count(char *str);
int					record_left_corner(char *piece);
int	ft_cover_bot_rev(char *map, char *piece, int e_co, int med_e, int play);
int	ft_cover_top_rev(char *map, char *piece, int place, int med_e, int play);
int	ft_cover_bottom_place(char *map, char *piece, int e_co, int play);
int	ft_cover_top_place(char *map, char *piece, int med_e, int play);
int	ft_check_dark_side(int e_corp, int med_e);
int	ft_check_mediane(char *map, int med_f, int med_e);
int	ft_place_anywhere(char *map, char *piece,char play);
int	ft_mediane_stg(char *map, char *piece, int med_f, char play);
int		ckeck_place_piece(char *str, char *piece, int i, char play);



void	call_place(char *str, int *tab, t_car *car, t_pos *pos, char *dst);
char	*ft_place_i(char *str, char *piece, int *tab, int i, char play);
char	*ft_reduct_piece(char *str, char *dst, int lim_g, int lim_d);
int		ft_control_check(char *map, char *piece, int i, char play);
int 	ft_correc_x(char *str);
int		ft_piece_diff(char *str);
int		ft_check_half_map(char *map);
int		ft_check_half_line(char *map);

int		ft_end_line(char *map, char play);
int		ft_nbr_line(char *map);
int 	ft_check_position(char *map, int med_f);
int	ft_check_tiers(char *map, int flag, char play);
int		ft_check_bound(char *map, int flag);







#endif
