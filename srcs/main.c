/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 15:39:03 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	exit_msg(int code)
{
	if (!code)
		printf("%s\n", "Error");
	if (code == 1)
		printf("%s\n", "Error: add the argument: the initial state and stage");
	if (code == 2)
		printf("%s\n", "Error: stack_overflow\n");
	if (code == 3)
		printf("%s\n", "Error: open_file error\n");
	if (code == 4)
		printf("%s\n", "Error: close_file error\n");
	if (code == 5)
		printf("%s\n", "Error: map_error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_map	*map_a;

	if (argc != 3)
		exit_msg (1);
	map = (t_map *)malloc(sizeof(*map));
	map_a = (t_map *)malloc(sizeof(*map_a));
	if (!map_a || !map)
		exit_msg(2);
	parse_state(argv[1], map);
	draw_test(map);
	adjasment(map);
	return (0);
}
