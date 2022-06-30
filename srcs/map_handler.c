/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:50 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/30 16:18:49 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	create_temp_map()
{
	int i = 0;

	temp_map = ft_memalloc(sizeof(int *) * g_data.lines);
	while (i < g_data.lines)
		temp_map[i++] = ft_memalloc(sizeof(int) * g_data.cols);
}

void	create_cell_coord()
{
	int i = 0;

	cell_coord = ft_memalloc(sizeof(t_cell_coord *) * g_data.lines);
	temp_cell_coord = ft_memalloc(sizeof(t_cell_coord *) * g_data.lines);
	while (i < g_data.lines)
	{
		cell_coord[i] = ft_memalloc(sizeof(t_cell_coord) * g_data.line_len);
		temp_cell_coord[i] = ft_memalloc(sizeof(t_cell_coord) * g_data.line_len);

		int j = 0;
		//to terminate the loop
		while (j < g_data.line_len)
		{
			temp_cell_coord[i][j].y = -1;
			cell_coord[i][j].y = -1;
			j++;
		}
		i++;
	}
}

void	copy_cell_coords()
{
	cell_coord[temp_coord_i][temp_coord_j].y = -1;
	while(temp_coord_i-- > 0)
	{
		while (temp_coord_j-- > 0)
		{
			cell_coord[temp_coord_i][temp_coord_j].y = temp_cell_coord[temp_coord_i][temp_coord_j].y;
			cell_coord[temp_coord_i][temp_coord_j].x = temp_cell_coord[temp_coord_i][temp_coord_j].x;
			cell_coord[temp_coord_i][temp_coord_j].bit_index = temp_cell_coord[temp_coord_i][temp_coord_j].bit_index;
		}
	}
}

void	draw_map(int **mep)
{
	int bit;
	int	i;
	int	j;
	char *temp = ft_memalloc(sizeof(*temp) * (MAX_BIT + 1));

	i = 0;
	while (i < g_data.lines)
	{
		j = 0;
		while (j < g_data.cols - 1)
		{
			bit = 0;
			while (bit < MAX_BIT)
			{
				if (check_bit(mep[i][j], bit))
					temp[bit] = 'x';
				else
					temp[bit] = '.';
				bit++;
			}
			printf("%s", temp);
			j++;
		}
		bit = 0;
		int remaining_length = g_data.line_len - (g_data.cols - 1) * MAX_BIT;
		while (bit < remaining_length)
		{
			if (check_bit(mep[i][j], bit))
				temp[bit] = 'x';
			else
				temp[bit] = '.';
			bit++;
		}
		temp[bit] = 0;
		printf("%s\n", temp);
		i++;
	}
}

void	copy_map(int **dst, int **src)
{
	int i;
	int j;

	i = 0;
	while (i < g_data.lines)
	{
		j = 0;
		while (j < g_data.cols)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
