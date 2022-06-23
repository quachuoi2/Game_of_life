/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_adjasment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:45:24 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 23:09:38 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void	*adjasment_9(t_map9 *map9)									// segment 9
{
	int	i;
	int	j;

	i = map9->map->i_start;
	while (i <= map9->map->i_max)
	{
		j = map9->j_start_t;
		while (j <= map9->j_max_t)
		{
			map9->map->map_a[i][j] = map9->map->map_g[i - 1][j + 1] + map9->map->map_g[i - 1][j] + \
							map9->map->map_g[i - 1][j - 1] + map9->map->map_g[i][j - 1] + \
							map9->map->map_g[i + 1][j - 1] + map9->map->map_g[i + 1][j] + \
							map9->map->map_g[i + 1][j + 1] + map9->map->map_g[i][j + 1];
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

	t_map9	*map9;

	// if (!(map9 == (t_map9 *)sizeof(*map9)))
	// 	exit_msg(2);

	map->i_start = 1;
	map->j_start = 1;
	map->i_max = map->lines - 2;
	map->j_max = map->cols - 2;
	if (map->cols * map->lines < MAX)
	{
		map9 = &(t_map9){map, 1, map->j_max};
		adjasment_9(map9);
	}
	// else
	// 	adjasment9_threads(map);
}
