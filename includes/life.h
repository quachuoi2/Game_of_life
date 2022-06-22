/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:15:11 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 16:22:19 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

// # include <../minilibx/mlx.h>
//# include <math.h>

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_map
{
	int				**map;
	int				*mapxy;
	int				cols;
	int				lines;
	char			*name;

}			t_map;

extern	t_map g_map;

void	parse_state(char *file);
void	exit_msg(int code);
void	draw_test();
void	pnl(int *nl, int len);

#endif