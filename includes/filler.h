/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:18:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/03/01 19:22:37 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_ply
{
	int				fd;
	int				nb;
	int				i;
	int				x;
	int				y;
	int				xp;
	int				yp;
	char			play;
	char			*line1;
	int				*tab;
	int				*tab2;
	char			*map;
	char			*piece;
	int				start;
	int				e_co;
	int				flag;
}					t_ply;

typedef struct		s_art
{
	int				max;
	int				min;
	int				i;
	int				j;
	int				start;
	int				e_co;
	int				x;
	int				y;
	int				x_map;
	int				y_map;
	int				pos;
	int				cpt;
	int				pos_ad;
	int				diff;
	char			play2;
	char			*res;
}					t_art;

typedef	struct		s_pos
{
	int				x;
	int				y;
	int				z;
	int				i;
	int				j;
	int				k;
	int				cpt;
	int				star;
	int				place;
	int				flag;
	int				piece;
	int				y_map;
	int				diff;
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
	int				i;
	int				pos;
	int				res;
	int				med_f;
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
int					ft_start_place(char *map, char play);
int					ft_enemy_start_place(char *map, char play);
char				ft_enemy_letter(char play);
int					ft_correc_x(char *str);
int					ft_convert_x(char *map, int conv);
int					ft_convert_y(char *map, int conv);
int					ft_count_stars(char *piece);
int					check_count(char *str);
int					record_left_corner(char *piece);
int					ft_place_anywhere(char *map, char *piece, char play);
int					ft_check_bound(char *map, int flag);
int					ft_check_tiers(char *map, int flag, char play);
int					ft_check_dark_side(int start, int e_co);
int					ft_nbr_line(char *map);
int					ft_mediane_point(char *map);
int					ft_check_mediane(char *map, char play);
int					check_enemy(char *map, char play2);
int					ft_cover_bottom_place(char *map, char *piece,
					int e_co, char play);
int					ft_cover_top_place(char *map, char *piece,
					int posi, char play);
int					ft_attack_position_classic(char *map, char *piece,
					char play, int e_co);
void				ft_strategy_attack(char *map, char *piece,
					t_stg *stg, char play);
int					ft_place_piece(char *map, char *piece,
					char play, t_art *art);
int					ft_check_battle(t_ply *ref);
void				ft_count_diff(char *str, t_pos *pos);
int					ft_piece_diff(char *str);
int					ft_piece_diff_end(char *str);
int					ft_count_piece(char *str, int lim_g, int lim_d);
int					check_diff(char *str, int i);
int					ft_check_line(char *piece);
int					ft_count_stars2(char *piece);
int					ft_star_line(char *str, int i);
int					ft_count_piece(char *str, int lim_g, int lim_d);
char				*ft_reduct_piece(char *str, char *dst,
					int lim_g, int lim_d);
int					ft_count_flag(char *str, int k);
int					ckeck_place_piece(char *str, char *piece, int i, char play);
int					ft_control_check(char *map, char *piece, int i, char play);
int					ref_point(char *map, int pos);
int					ref_point_inv(char *map, int pos);
int					ft_advance_point_top(char *str, char play);
int					ft_advance_point_bot(char *str, char play);
int					ft_attack(char *map, char *piece, char play);
int					ft_place_anywhere_inv(char *map, char *piece, char play);
int					ft_attack_bot(char *map, char *piece, char play);
int					last_line_inv(char *map, char play);
int 				last_line(char *map, char play);
int					ft_attack_inv_top(char *map, char *piece, char play);
int					ft_attack_inv_bot(char *map, char *piece, char play);






#endif
