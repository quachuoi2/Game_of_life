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

void	bit_flip(int i, int j, int bit_index, int surrounding)
{
	if (check_bit(real_map[i][j], bit_index))
	{
		if (surrounding != 2 && surrounding != 3)
			temp_map[i][j] &= ~(1 << bit_index);
	}
	else if (surrounding == 3)
		temp_map[i][j] |= 1 << bit_index;
}

void	check_top_bottom_border()
{
	int j = 0;
	int last_row = g_data.lines - 1;
	register int top_surrounding;
	register int bot_surrounding;
	int bit_index;

	while (j < g_data.cols - 1)
	{
		bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			top_surrounding = check_top(j, bit_index);
			bot_surrounding = check_bottom(last_row, j, bit_index);

			bit_flip(0, j, bit_index, top_surrounding);
			bit_flip(last_row, j, bit_index, bot_surrounding);

			bit_index++;
		}
		j++;
	}
	bit_index = 0;
	while (bit_index < g_data.remaining_length)
	{
		top_surrounding = check_top(j, bit_index);
		bot_surrounding = check_bottom(last_row, j, bit_index);

		bit_flip(0, j, bit_index, top_surrounding);
		bit_flip(last_row, j, bit_index, bot_surrounding);

		bit_index++;
	}
	j++;

}

int	check_line(void *i)
{
	int	j = 0;
	int bit_index;
	register int surrounding;

	while (j < g_data.cols - 1)
	{
		bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			surrounding = check_surrounding(*(int *)i, j, bit_index);
			bit_flip(*(int *)i, j, bit_index, surrounding);
			bit_index++;
		}
		j++;
	}
	bit_index = 0;
	while (bit_index < g_data.remaining_length)
	{
		surrounding = check_last_int_surrounding(*(int *)i, j, bit_index);
		bit_flip(*(int *)i, j, bit_index, surrounding);
		bit_index++;
	}
	return (0);
}

void	check_the_middle_guys()
{
	int	i = 1;
	int max_row = g_data.lines - 1;

	while (i < max_row)
	{
		//multithreading(i);
		check_line(&i);
		i++;
	}
}

void	play_n_turn(char *turn)
{
	int i = atoi(turn);
	while (i--)
	{
		//why does this work?
		check_top_bottom_border(temp_map, real_map, g_data);
		check_the_middle_guys(temp_map, real_map, g_data);
		//and is faster than this
		// check_top_bottom_border();
		// check_the_middle_guys();
		copy_map(real_map, temp_map);
	}
	draw_map(real_map);
}
