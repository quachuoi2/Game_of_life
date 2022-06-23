/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 00:30:17 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

// # include <../minilibx/mlx.h>

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 1078

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

}					t_map;

void	parse_map(char *file, t_map *map);
void	parse_state(char *file, t_map *map);
void	exit_msg(int code);
void	draw_map(t_map *map);
void	adjasment(t_map *map);
void	life(t_map *map, char *str);

#endif