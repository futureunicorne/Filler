/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:18:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/13 07:28:53 by hel-hadi         ###   ########.fr       */
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
	char	*map;
	char	*piece;
}				t_ply;

typedef struct	s_art
{
	int		max;
	int 	min;
	int		i;
	int		j;
	int		pos;
	int		pos_ad;
	char	play2;
}				t_art;

int		recovery_place(int fd, char *str);
char	ft_record_playnbr(int fd);
int		*ft_record_size_map(int fd);
int		*ft_record_size_piece(int fd);
char	*ft_record_map(int lgt, int fd);
char	*ft_record_piece(int lgt, int fd);
int		ft_start_place(char *map, char play);
int		*ft_check_battle(char *map, char *piece, char play, int x_map);







#endif
