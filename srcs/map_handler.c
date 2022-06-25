/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:28:50 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/25 09:43:59 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	create_temp_map()
{
	int i = 0;

	temp_map = ft_memalloc(sizeof(int *) * g_map.lines);
	while (i < g_map.lines)
		temp_map[i++] = ft_memalloc(sizeof(int) * g_map.cols);
}

void	draw_map(int **mep)
{
	int bit;
	int	i;
	int	j;
	char *temp = ft_memalloc(sizeof(*temp) * (MAX_BIT + 1));

	i = 0;
	while (i < g_map.lines)
	{
		j = 0;
		while (j < g_map.cols - 1)
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
		ft_bzero(temp, MAX_BIT + 1);
		bit = 0;
		int remaining_length = g_map.temp_cols - (g_map.cols - 1) * MAX_BIT;
		while (bit < remaining_length)
		{
			if (check_bit(mep[i][j], bit))
				temp[bit] = 'x';
			else
				temp[bit] = '.';
			bit++;
		}
		printf("%s\n", temp);
		i++;
	}
}

void	copy_map(int **dst, int **src)
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
