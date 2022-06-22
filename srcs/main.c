/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 12:40:51 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	exit_msg(int code)
{
	if (!code)
		write(1, "Error\n", 6);
	if (code == 1)
		write(1, "Error: add the 1 argument\n", 27);
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
	t_map	*map;

	if (argc != 2)
		exit_msg (1);
	map = (t_map *)malloc(sizeof(*map));
	if (!map)
		exit_msg(2);
	parse_state(argv[1], map);
	draw_test(map);
	// handle_image(map);
	return (0);
}
