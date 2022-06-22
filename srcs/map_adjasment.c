/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjasment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:45:24 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 19:01:55 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	adjasment_9(t_map *map, int i, int j_start, int i_max, int j_max)
{
	int	j;
	int	a;

	while (i <= i_max)
	{
		j = j_start;
		while (j <= j_max)
		{
			/*map->map_a[i][j]*/ a = map->map[i - 1][j + 1] + map->map[i - 1][j] + \
							map->map[i - 1][j - 1] + map->map[i][j - 1] + \
							map->map[i + 1][j - 1] + map->map[i + 1][j] + \
							map->map[i + 1][j + 1] + map->map[i][j + 1];
			// printf("%3d\n", map->map_a[i][j]);
			map->map_a[i][j] = a;
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

	map->map_a[0][0] = map->map[0][1] + map->map[1][1] + map->map[1][0];  // segment 1
	map->map_a[0][cols_index] = map->map[1][cols_index] + map->map[1][cols_index - 1] + map->map[0][cols_index - 1];  // segment 2
	map->map_a[lines_index][0] = map->map[lines_index - 1][0] + map->map[lines_index - 1][1] + map->map[lines_index][1];  // segment 3
	map->map_a[lines_index][cols_index] = map->map[lines_index][cols_index - 1] + map->map[lines_index - 1][cols_index - 1] + map->map[lines_index - 1][cols_index];  // segment 4

	i = 0;
	j = 1;
	while (j < cols_index - 1) // segment 5
		map->map_a[i][j++] = 0;
	i = lines_index;
	j = 1;
	while (j < cols_index - 1)  // segment 7
		map->map_a[i][j++] = 0;
	i = 1;
	j = 0;
	while (i < lines_index - 1)  // segment 8
		map->map_a[i++][j] = 0;
	i = 1;
	j = cols_index;
	while (i < lines_index - 1) // segment 6
		map->map_a[i++][j] = 0;
	if (map->cols * map->lines < MAX)
	{
		adjasment_9(map, 1, 1, lines_index - 1, cols_index - 1); // segment 9
	}
}
