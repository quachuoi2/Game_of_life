/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:28:21 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/30 17:52:50 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	check_live_cell()
{
	int i = 0;
	int j = 0;
	temp_coord_i = 0;
	temp_coord_j = 0;

	while (cell_coord[i][j].y != -1)
	{
		int	surrounding = check_surrounding(cell_coord[i][j].y, cell_coord[i][j].x, cell_coord[i][j].bit_index);
		if (surrounding != 2 && surrounding != 3)
			temp_map[cell_coord[i][j].y][cell_coord[i][j].x] &= ~(1 << cell_coord[i][j].bit_index);
		else
		{
			temp_cell_coord[temp_coord_i][temp_coord_j].y = cell_coord[i][j].y;
			temp_cell_coord[temp_coord_i][temp_coord_j].x = cell_coord[i][j].x;
			temp_cell_coord[temp_coord_i][temp_coord_j].bit_index = cell_coord[i][j].bit_index;
			temp_coord_j++;
			if (temp_coord_j == g_data.line_len)
			{
				temp_coord_j = 0;
				temp_coord_i++;
			}
		}

		j++;
		if (j == g_data.line_len)
		{
			j = 0;
			i++;
		}
	}
	temp_cell_coord[temp_coord_i][temp_coord_j].y = -1;
}

void	do_thing()
{
	int i = 0;
	int j = 0;
	while (cell_coord[i][j].y != -1)
	{
		printf("%d %d %d\n", cell_coord[i][j].y, cell_coord[i][j].x, cell_coord[i][j].bit_index);
		j++;
		if (j == g_data.line_len)
		{
			j = 0;
			i++;
		}
	}
}

void	play_n_turn_2(char *turn)
{
	int i = atoi(turn);
	while (i--)
	{
		draw_map(real_map);
		do_thing();
		check_live_cell();
		copy_cell_coords();
		copy_map(real_map, temp_map);
	}
		draw_map(real_map);
}