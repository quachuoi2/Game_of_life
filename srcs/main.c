/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/27 13:01:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

t_map	g_data;
int		**real_map;
int		**temp_map;

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

	g_data.lines = atoi(argv[3]);
	real_map = ft_memalloc(sizeof(*real_map) * g_data.lines);
	parse_state(argv[1]);
	create_temp_map(temp_map, real_map);
	copy_map(temp_map, real_map);
	play_n_turn(argv[2]);
	return (0);
}
