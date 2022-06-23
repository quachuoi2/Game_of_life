/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 19:43:56 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

// # include <../minilibx/mlx.h>
//# include <math.h>

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "libftprintf.h"
# define MAX_BIT 32
typedef struct s_map
{
	int				cols;
	int				temp_cols;
	int				lines;
	char			*name;
	long int		**map;

}			t_map;

extern	t_map g_map;
extern long int **temp_map;

void	parse_state(char *file);
void	exit_msg(int code);
void	draw_map(long int **mep);
void	pnl(int *nl, int len);
void	free_everything();
void	game_of_life();
void	copy_map(long int **dst, long int **src);
void	create_temp_map();
int		check_bit(long int num, int n);
void	delay(int number_of_seconds);
void	infinite_gaming();
void	play_n_turn(char *turn);
int		check_left_bit(int i, int j, int bit_index);
int		check_right_bit(int i, int j, int bit_index);
int		check_surrounding(int i, int j, int bit_index);


#endif