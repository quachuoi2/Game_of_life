/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 18:46:18 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

// void	draw_map(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map->lines)
// 	{
// 		j = 0;
// 		while (j < map->cols)
// 		{
// 			printf("%3d", map->map_g[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

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
	if (code == 6)
		printf("%s\n", "Error: in threads\n");
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
	life(map, argv[2]);
	draw_map(map);
	return (0);
}
