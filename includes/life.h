/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/25 12:38:36 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "threads.h"
# define MAX_BIT 16
# define THREAD_COUNT 7
typedef struct s_map
{
	int	cols;
	int	temp_cols;
	int	lines;
	int	**map;

}			t_map;

extern	t_map g_map;
extern int **temp_map;

//parse.c
void	parse_state(char *file);
//map_handler.c
void	draw_map(int **mep);
//void	copy_map(int **dst, int **src);
void	copy_map(int **dst, int **src);
void	create_temp_map();
//bonus.c
void	delay(int number_of_seconds);
void	infinite_gaming();
//algo.c
//void	check_the_middle_guys();
void	check_top_bottom_border();
void	check_the_middle_guys();
void	play_n_turn(char *turn);
//abomination.c
int		check_bit(int num, int n);
int		check_surrounding(int i, int j, int bit_index);
int		check_top(int j, int bit_index);
int		check_bottom(int i, int j, int bit_index);

//main.c
void	exit_msg(int code);

#endif