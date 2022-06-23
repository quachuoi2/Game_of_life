/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 23:04:55 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

// # include <../minilibx/mlx.h>

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

# define MAX 1000000
# define BUFF_SIZE 1078
# define THREADS 8

typedef struct s_map
{
	int				**map_g;
	int				**map_a;
	int				cols; // i
	int				lines; // j
	int				i_start;
	int				j_start;
	int				i_max;
	int				j_max;
	int				pos_j;

}					t_map;

typedef struct s_thread
{
	// int			thread;
	t_map			map;
	int				j_start_t;
	int				j_max_t;

}					t_thread;

typedef struct s_map9
{
	// int			thread;
	// t_map			pos
	// t_map			end;
	t_map			*map;
	int				j_start_t;
	int				j_max_t;

}					t_map9;

void	parse_map(char *file, t_map *map);
void	parse_state(char *file, t_map *map);
void	exit_msg(int code);
void	draw_map(t_map *map);
void	adjasment(t_map *map);
void	life(t_map *map, char *str);

#endif