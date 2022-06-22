/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 00:24:55 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

t_map	g_map;
long int **temp_map;

void	exit_msg(int code)
{
	if (!code)
		write(1, "Error\n", 6);
	if (code == 2)
		write(1, "Error: stack_overflow\n", 23);
	if (code == 3)
		write(1, "Error: open_file error\n", 23);
	if (code == 4)
		write(1, "Error: close_file error\n", 23);
	if (code == 5)
		write(1, "Error: map_error\n", 23);
	exit(0);
}

int	main(int argc, char **argv)
{
	//convert the arg to number and assign that number to map.lines
	g_map.lines = ft_atoi(argv[3]);
	g_map.map = ft_memalloc(sizeof(*g_map.map) * g_map.lines);

	parse_state(argv[1]);

	create_temp_map();
	copy_map(temp_map, g_map.map);

	play_n_turn(argv[2]);
	//infinite_gaming();

	free_everything();
	return (0);
}
