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

int		check_bit(long int num, int n)
{
	return (num & (1 << n));
}

int		check_surrounding(int i, int j, int bit_index)
{
	int counter = 0;

	if (check_left_bit(i, j, bit_index))
		counter++;
	if (check_right_bit(i, j, bit_index))
		counter++;

//check bits on the row above
	if (i > 0)
	{
		if (check_left_bit(i - 1, j, bit_index))
			counter++;
		if (check_bit(g_map.map[i - 1][j], bit_index))
			counter++;
		if (check_right_bit(i - 1, j, bit_index))
			counter++;
	}

//check bits on the row below
	if (i < g_map.lines - 1)
	{
		if (check_left_bit(i + 1, j, bit_index))
			counter++;
		if (check_bit(g_map.map[i + 1][j], bit_index))
			counter++;
		if (check_right_bit(i + 1, j, bit_index))
			counter++;
	}
	return (counter);
}

void	game_of_life()
{
	int bit_index;
	int	i;
	int	j;
	int surrounding;

	i = 0;
	while (i < g_map.lines)
	{
		j = 0;
		while (j < g_map.cols)
		{
			bit_index = 0;
			while (bit_index < 8)
			{
				surrounding = check_surrounding(i, j, bit_index);
				if ((surrounding != 2 && surrounding != 3 && check_bit(g_map.map[i][j], bit_index))
					|| (surrounding == 3 && !check_bit(g_map.map[i][j], bit_index)))
					temp_map[i][j] ^= 1 << bit_index;
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
