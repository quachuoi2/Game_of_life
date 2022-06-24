/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:30:09 by mrozhnova        ###   ########.fr       */
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
	uint8_t			**map_g;
	uint8_t			**map_a;
	uint64_t		cols;		// i
	uint64_t		lines;		// j
	uint64_t		i_start;
	uint64_t		j_start;
	uint64_t		i_max;
	uint64_t		j_max;

}					t_map;

void	parse_map(char *file, t_map *map);
void	parse_state(char *file, t_map *map);
void	exit_msg(int code);
void	draw_map(t_map *map);
void	adjasment(t_map *map);
void	life(t_map *map, char *str);

#endif