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

void	check_top_bottom_border(int tomb_map[g_map.lines][g_map.cols])
{
	int j = 0;
	int last_row = g_map.lines - 1;
	while (j < g_map.cols)
	{
		int bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			register int top_surrounding = check_top(j, bit_index);
			register int bot_surrounding = check_bottom(last_row, j, bit_index);

			if (check_bit(g_map.map[0][j], bit_index))
			{
				if (top_surrounding != 2 && top_surrounding != 3)
					tomb_map[0][j] &= ~(1 << bit_index);
			}
			else if (top_surrounding == 3)
				tomb_map[0][j] |= 1 << bit_index;

			if (check_bit(g_map.map[last_row][j], bit_index))
			{
				if (bot_surrounding != 2 && bot_surrounding != 3)
					tomb_map[last_row][j] &= ~(1 << bit_index);
			}
			else if (bot_surrounding == 3)
				tomb_map[last_row][j] |= 1 << bit_index;

			bit_index++;
		}
		j++;
	}
}

void	check_the_middle_guys(int tomb_map[g_map.lines][g_map.cols])
{
	int	i = 1;
	while (i < g_map.lines - 1)
	{
		int	j = 0;
		while (j < g_map.cols)
		{
			int bit_index = 0;
			while (bit_index < MAX_BIT)
			{
				register int surrounding = 	check_surrounding(i, j, bit_index);
				if (check_bit(g_map.map[i][j], bit_index))
				{
					if (surrounding != 2 && surrounding != 3)
						tomb_map[i][j] &= ~(1 << bit_index);
				}
				else if (surrounding == 3)
					tomb_map[i][j] |= 1 << bit_index;
				bit_index++;
			}
			j++;
		}
		i++;
	}
}

void	play_n_turn(char *turn, int tomb_map[g_map.lines][g_map.cols])
{
	int i = ft_atoi(turn);
	while (i--)
	{
		check_top_bottom_border(tomb_map);
		check_the_middle_guys(tomb_map);
		copy_map2(g_map.map, tomb_map);
	}
	draw_map(g_map.map);
}
