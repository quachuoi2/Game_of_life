/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 16:43:19 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

// # include <../minilibx/mlx.h>

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <unistd.h> // should be delated
# include <stdio.h>

# define MAX 1000000
# define BUFF_SIZE 40

typedef struct s_map
{
	int				**map_g;
	int				**map_a;
	int				cols; // i
	int				lines; // j

}			t_map;

void	parse_map(char *file, t_map *map);
void	parse_state(char *file, t_map *map);
void	exit_msg(int code);
void	draw_map(t_map *map);
void	adjasment(t_map *map);
void	life(t_map *map, char *str);

#endif