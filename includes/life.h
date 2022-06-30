/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/30 16:27:59 by qnguyen          ###   ########.fr       */
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

typedef struct	s_map
{
	short int	cols;
	int			line_len;
	int			lines;
	int			remaining_length;
}				t_map;

typedef struct	s_cell_coord
{
	int y;
	int	x;
	int	bit_index;
}				t_cell_coord;

extern t_map		g_data;
extern int			**real_map;
extern int			**temp_map;
extern t_cell_coord	**cell_coord;
extern t_cell_coord	**temp_cell_coord;
extern int			temp_coord_i;
extern int			temp_coord_j;
//parse.c
void	parse_state(char *file, int line_count);
//map_handler.c
void	draw_map(int **mep);
void	copy_single_cell_coord(t_cell_coord *dst, t_cell_coord src);
void	copy_cell_coords();
void	copy_map(int **dst, int **src);
void	create_temp_map();
void	create_cell_coord();
//bonus.c
void	delay(int number_of_seconds);
void	infinite_gaming();

//algo.c
void	check_top_bottom_border();
void	check_the_middle_guys();
void	play_n_turn(char *turn);
void	play_n_turn_2(char *turn);
int		check_line(void *i);

//abomination.c
int		check_bit(int num, int n);
int		check_dead_surrounding(int i, int j, int bit_index);
int		check_surrounding(int i, int j, int bit_index);
int		check_last_int_surrounding(int i, int j, int bit_index);
int		check_top(int j, int bit_index);
int		check_bottom(int i, int j, int bit_index);

//threads.c
void	multithreading(int i);

//main.c
void	exit_msg(int code);

#endif