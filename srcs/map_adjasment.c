/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjasment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:45:24 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 21:35:20 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	adjasment_9(t_map *map, int i, int j_start, int i_max, int j_max)
{
	int	j;

	while (i <= i_max)
	{
		j = j_start;
		while (j <= j_max)
		{
			map->map_a[i][j] = map->map_g[i - 1][j + 1] + map->map_g[i - 1][j] + \
							map->map_g[i - 1][j - 1] + map->map_g[i][j - 1] + \
							map->map_g[i + 1][j - 1] + map->map_g[i + 1][j] + \
							map->map_g[i + 1][j + 1] + map->map_g[i][j + 1];
			// printf("%3d\n", map->map_a[i][j]);
			j++;
		}
		i++;
	}
}

void adjasment(t_map *map)
{
	int	i, j;

	int	cols_index = map->cols - 1;
	int	lines_index = map->lines - 1;

	map->map_a[0][0] = map->map_g[0][1] + map->map_g[1][1] + map->map_g[1][0];  // segment 1
	map->map_a[0][cols_index] = map->map_g[1][cols_index] + map->map_g[1][cols_index - 1] + map->map_g[0][cols_index - 1];  // segment 2
	map->map_a[lines_index][0] = map->map_g[lines_index - 1][0] + map->map_g[lines_index - 1][1] + map->map_g[lines_index][1];  // segment 3
	map->map_a[lines_index][cols_index] = map->map_g[lines_index][cols_index - 1] + map->map_g[lines_index - 1][cols_index - 1] + map->map_g[lines_index - 1][cols_index];  // segment 4

	j = 1;
	while (j < cols_index)   // segments 6 && 8
	{
		map->map_a[0][j] = map->map_g[0][j - 1] + \
							map->map_g[1][j - 1] + map->map_g[1][j] + \
							map->map_g[1][j + 1] + map->map_g[0][j + 1];
		map->map_a[lines_index][j] =  map->map_g[lines_index - 1][j + 1] + \
							map->map_g[lines_index - 1][j] + \
							map->map_g[lines_index - 1][j - 1] + \
							map->map_g[lines_index][j - 1] + \
							map->map_g[lines_index][j + 1];
		j++;
	}
	i = 1;
	while (i < lines_index)  // segment 7 && 5
	{
		map->map_a[i][0] =  map->map_g[i - 1][1] + map->map_g[i - 1][0] + \
							map->map_g[i + 1][0] + map->map_g[i + 1][1] + \
							map->map_g[i][1];
		map->map_a[i][cols_index] = map->map_g[i - 1][cols_index] + \
							map->map_g[i - 1][cols_index - 1] + \
							map->map_g[i][cols_index - 1] + \
							map->map_g[i + 1][cols_index - 1] + \
							map->map_g[i + 1][cols_index];
		i++;
	}

	if (map->cols * map->lines < MAX)
	{
		adjasment_9(map, 1, 1, lines_index - 1, cols_index - 1); // segment 9
	}
}
