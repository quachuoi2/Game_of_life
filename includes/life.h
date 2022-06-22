/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 10:52:06 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <../minilibx/mlx.h>

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <unistd.h>

typedef struct s_map
{
	int				**map;
	int				*mapxy;
	int				cols;
	int				lines;
	int				maxz;
	char			*name;

}			t_map;

void	parse_state(char *file, t_map *map);
void	exit_msg(int code);

#endif