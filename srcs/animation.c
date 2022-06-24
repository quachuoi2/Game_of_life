/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 04:52:04 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

t_map	g_map;

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
	g_map.lines = atoi(argv[2]);
	g_map.map = ft_memalloc(sizeof(*g_map.map) * g_map.lines);
	parse_state(argv[1]);
	int	tomb_map[g_map.lines][g_map.cols];
	copy_map1(tomb_map, g_map.map);
	infinite_gaming(tomb_map);
	return (0);
}
