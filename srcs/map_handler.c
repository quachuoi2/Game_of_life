/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:50 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/23 00:06:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	create_temp_map()
{
	int i;

	i = 0;
	temp_map = ft_memalloc(sizeof(long int *) * g_map.lines);
	while (i < g_map.lines)
		temp_map[i++] = ft_memalloc(sizeof(long int) * g_map.cols);
}

void	draw_map(long int **mep)
{
	int	i;
	int	j;
	int bit_index;
	char	*temp_line;

	i = 0;
	temp_line = ft_memalloc(sizeof(char) * (g_map.temp_cols + 1));
	while (i < g_map.lines)
	{
		j = 0;
		bit_index = 0;
		while (j < g_map.cols - 1)
		{
			//ft_printf("%.*llb", MAX_BIT, mep[i][j]);
			while (bit_index < g_map.temp_cols)
			{
				if (check_bit(mep[i][j], bit_index))
					temp_line[g_map.temp_cols - bit_index] = 'x';
				else
					temp_line[g_map.temp_cols - bit_index] = '.';
				bit_index++;
			}
			printf("%s", temp_line);
			j++;
		}
		//ft_printf("%.*b", g_map.temp_cols - ((g_map.cols - 1) * MAX_BIT), mep[i][j]);
		bit_index = 0;
		while (bit_index <= g_map.temp_cols - ((g_map.cols - 1) * MAX_BIT))
		{
			if (check_bit(mep[i][j], bit_index))
				temp_line[g_map.temp_cols - bit_index - 1] = 'x';
			else
				temp_line[g_map.temp_cols - bit_index - 1] = '.';
			bit_index++;
		}
		printf("%s\n", temp_line);
		i++;
	}
}

void	copy_map(long int **dst, long int **src)
{
	int i;
	int j;

	i = 0;
	while (i < g_map.lines)
	{
		j = 0;
		while (j < g_map.cols)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
