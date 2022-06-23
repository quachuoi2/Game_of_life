/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:14:58 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:11:01 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	draw_map(t_map *map)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map_g[i][j] == 0)
				printf("%c", '.');
			else if (map->map_g[i][j] == 1)
				printf("%c", 'X');
			j++;
		}
		printf("\n");
		i++;
	}
}
