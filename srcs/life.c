/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:42:02 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:25:02 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static uint8_t	generation(t_map *map)
{
	uint64_t	i;
	uint64_t	j;
	uint8_t		life;

	life = 0;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map_g[i][j] == 1 && (map->map_a[i][j] < 2 || (map->map_a[i][j] > 3)))
			{
				map->map_g[i][j] = 0;
				life = 1;
			}
			else if (map->map_g[i][j] == 0 && map->map_a[i][j] == 3)
			{
				map->map_g[i][j] = 1;
				life = 1;
			}
			j++;
		}
		i++;
	}
	return(life);
}

void	life(t_map *map, char *str)
{
	uint64_t		i;
	uint64_t		count;

	count = ft_atoi(str);
	printf("\033[38;5;214mLife has the %1llu interations\033[0m\n", count);
	i = 0;
	while (i < count)
	{
		adjasment(map);
		if (!generation(map))
		{
			printf("\033[38;5;214mThe Life has been stabled after the the %1llu iteration\033[0m\n", i);
			break;
		}
		i++;
	}
}
