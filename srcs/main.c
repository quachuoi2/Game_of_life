/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/30 17:42:34 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

t_map			g_data;
int				**real_map;
int				**temp_map;
t_cell_coord	**cell_coord;
t_cell_coord	**temp_cell_coord;
int				temp_coord_i;
int				temp_coord_j;

void	exit_msg(int code)
{
	if (!code)
		printf("Error\n");
	if (code == 2)
		printf("Error: stack_overflow\n");
	if (code == 3)
		printf("Error: open_file error\n");
	if (code == 4)
		printf("Error: close_file error\n");
	if (code == 5)
		printf("Error: map_error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	parse_state(argv[1], atoi(argv[3]));
	copy_map(temp_map, real_map);
	play_n_turn_2(argv[2]);

	return (0);
}
