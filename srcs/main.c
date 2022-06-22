/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 14:02:02 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	exit_msg(int code)
{
	if (!code)
		printf("%s\n", "Error");
	if (code == 1)
		printf("%s\n", "Error: add the initial stateargument and stage");
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

	if (argc != 3)
		exit_msg (1);
	map = (t_map *)malloc(sizeof(*map));
	if (!map)
		exit_msg(2);
	parse_state(argv[1], map);
	draw_test(map);
	return (0);
}
