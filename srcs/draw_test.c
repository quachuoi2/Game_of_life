/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:14:58 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 17:45:08 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	draw_test(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			printf("%3d", map->map_a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
