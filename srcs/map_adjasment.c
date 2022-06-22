/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjasment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:45:24 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 15:27:27 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	adjasment_9(t_map *map, int i, int j_start, int i_max, int j_max)
{
	int	j;

	while (i < i_max)
	{
		j = j_start;
		while (j < j_max)
		{
			map->map_a[i][j] = map->map[i - 1][j + 1] + map->map[i - 1][j] + \
							map->map[i - 1][j - 1] + map->map[i][j - 1] + \
							map->map[i + 1][j - 1] + map->map[i + 1][j] + \
							map->map[i + 1][j + 1] + map->map[i][j + 1];
			printf("%3d\n", map->map_a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void adjasment(t_map *map)
{
	if (map->cols * map->lines < MAX)
	{
		adjasment_9(map, 1, 1, map->lines - 1, map->cols - 1);
	}
}
