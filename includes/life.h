/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:48:05 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MAX_BIT 16

typedef struct s_map
{
	int	cols;
	int	temp_cols;
	int	lines;
	int	**map;

}			t_map;

extern	t_map g_map;
extern int **temp_map;

void	parse_state(char *file);
void	exit_msg(int code);
void	draw_map(int **mep);
void	game_of_life();
void	copy_map(int **dst, int **src);
void	create_temp_map();
int		check_bit(int num, int n);
void	delay(int number_of_seconds);
void	infinite_gaming();
void	play_n_turn(char *turn);
int		check_left_bit(int i, int j, int bit_index);
int		check_right_bit(int i, int j, int bit_index);
int		check_surrounding(int i, int j, int bit_index);

#endif