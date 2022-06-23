	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:17:14 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/22 21:45:45 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	game_of_life()
{
	int	i = 0;
	while (i < g_map.lines)
	{
		int	j = 0;
		while (j < g_map.cols)
		{
			int bit_index = 0;
			while (bit_index < MAX_BIT)
			{
				int surrounding = check_surrounding(i, j, bit_index);
				if (check_bit(g_map.map[i][j], bit_index))
				{
					if (surrounding != 2 && surrounding != 3)
						temp_map[i][j] &= ~(1 << bit_index);
				}
				else if (surrounding == 3)
					temp_map[i][j] |= 1 << bit_index;
				bit_index++;
			}
			j++;
		}
		i++;
	}
}

void	play_n_turn(char *turn)
{
	int i = ft_atoi(turn);
	while (i--)
	{
		game_of_life();
		copy_map(g_map.map, temp_map);
	}
	draw_map(g_map.map);
}
