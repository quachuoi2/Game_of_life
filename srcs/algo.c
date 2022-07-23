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

/* void	bit_flip(int i, int j, int bit_index, int surrounding)
{
	if (check_bit(real_map[i][j], bit_index))
	{
		if (surrounding != 2 && surrounding != 3)
			temp_map[i][j] &= ~(1 << bit_index);
	}
	else if (surrounding == 3)
		temp_map[i][j] |= 1 << bit_index;
} */

void	check_top_bottom_border()
{
	int j = 0;
	int last_row = g_data.lines - 1;
	int bit_index;
	while (j < g_data.cols - 1)
	{
		bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			register int top_surrounding = check_top_bottom_surrounding(1, j, bit_index, 0);
			register int bot_surrounding = check_top_bottom_surrounding(last_row, j, bit_index, 0);

			// bit_flip(0, j, bit_index, top_surrounding);
			// bit_flip(last_row, j, bit_index, bot_surrounding);

			if (check_bit(real_map[0][j], bit_index))
			{
				if (top_surrounding != 2 && top_surrounding != 3)
					temp_map[0][j] &= ~(1 << bit_index);
			}
			else if (top_surrounding == 3)
				temp_map[0][j] |= 1 << bit_index;

			if (check_bit(real_map[last_row][j], bit_index))
			{
				if (bot_surrounding != 2 && bot_surrounding != 3)
					temp_map[last_row][j] &= ~(1 << bit_index);
			}
			else if (bot_surrounding == 3)
				temp_map[last_row][j] |= 1 << bit_index;

			bit_index++;
		}
		j++;
	}
	bit_index = 0;
	while (bit_index < g_data.remaining_length)
	{
		register int top_surrounding = check_top_bottom_surrounding(1, j, bit_index, 0);
		register int bot_surrounding = check_top_bottom_surrounding(last_row, j, bit_index, 0);
		// bit_flip(0, j, bit_index, top_surrounding);
		// bit_flip(last_row, j, bit_index, bot_surrounding);

		if (check_bit(real_map[0][j], bit_index))
		{
			if (top_surrounding != 2 && top_surrounding != 3)
				temp_map[0][j] &= ~(1 << bit_index);
		}
		else if (top_surrounding == 3)
			temp_map[0][j] |= 1 << bit_index;

		if (check_bit(real_map[last_row][j], bit_index))
		{
			if (bot_surrounding != 2 && bot_surrounding != 3)
				temp_map[last_row][j] &= ~(1 << bit_index);
		}
		else if (bot_surrounding == 3)
			temp_map[last_row][j] |= 1 << bit_index;

		bit_index++;
	}
}

void	check_the_middle_guys()
{
	int	i = 1;
	int max_row = g_data.lines - 1;

	while (i < max_row)
	{
		int	j = 0;
		int bit_index;
		register int surrounding;

		while (j < g_data.cols - 1)
		{
			bit_index = 0;
			while (bit_index < MAX_BIT)
			{
				surrounding = check_surrounding(i, j, bit_index, 0);
				//bit_flip(i, j, bit_index, surrounding);
				if (check_bit(real_map[i][j], bit_index))
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
		bit_index = 0;
		while (bit_index < g_data.remaining_length)
		{
			surrounding = check_surrounding(i, j, bit_index, 1);
			//bit_flip(i, j, bit_index, surrounding);
			if (check_bit(real_map[i][j], bit_index))
			{
				if (surrounding != 2 && surrounding != 3)
					temp_map[i][j] &= ~(1 << bit_index);
			}
			else if (surrounding == 3)
				temp_map[i][j] |= 1 << bit_index;

			bit_index++;
		}
		i++;
	}
}

void	play_n_turn(char *turn)
{
	int i = ft_atoi(turn);
	while (i--)
	{
		//why does this work? Passing global vars as arguments to a function that takes no parameter.
		//System: Ubuntu - WSL
		check_top_bottom_border(temp_map, real_map, g_data);
		check_the_middle_guys(temp_map, real_map, g_data);
		//and is faster than this
		// check_top_bottom_border();
		// check_the_middle_guys();
		copy_map(real_map, temp_map);
	}
	draw_map(real_map);
}
