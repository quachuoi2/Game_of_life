/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjasment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:45:24 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:08:45 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void	adjasment_9(t_map *map)									// segment 9
{
	uint8_t	i;
	uint8_t	j;

	i = map->i_start;
	while (i <= map->i_max)
	{
		j = map->j_start;
		while (j <= map->j_max)
		{
			map->map_a[i][j] = map->map_g[i - 1][j + 1] + map->map_g[i - 1][j] + \
							map->map_g[i - 1][j - 1] + map->map_g[i][j - 1] + \
							map->map_g[i + 1][j - 1] + map->map_g[i + 1][j] + \
							map->map_g[i + 1][j + 1] + map->map_g[i][j + 1];
			j++;
		}
		i++;
	}
}

void adjasment(t_map *map)
{
	uint8_t	i, j;

	uint8_t	cols_index = map->cols - 1;
	uint8_t	lines_index = map->lines - 1;

	map->map_a[0][0] = map->map_g[0][1] + \
						map->map_g[1][1] + \
						map->map_g[1][0];							// segment 1
	map->map_a[0][cols_index] = map->map_g[1][cols_index] + \
						map->map_g[1][cols_index - 1] + \
						map->map_g[0][cols_index - 1];				// segment 2
	map->map_a[lines_index][0] = map->map_g[lines_index - 1][0] + \
						map->map_g[lines_index - 1][1] + \
						map->map_g[lines_index][1];					// segment 3
	map->map_a[lines_index][cols_index] = map->map_g[lines_index][cols_index - 1] + \
						map->map_g[lines_index - 1][cols_index - 1] + \
						map->map_g[lines_index - 1][cols_index];	// segment 4

	j = 1;
	while (j < cols_index)											// segments 6 && 8
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
	while (i < lines_index)											// segment 7 && 5
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

	map->i_start = 1;
	map->j_start = 1;
	map->i_max = map->lines - 2;
	map->j_max = map->cols - 2;
	adjasment_9(map);
}
