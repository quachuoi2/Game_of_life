/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abomination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/27 13:03:04 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

int		check_bit(int num, int n)
{
	if (num & (1 << n))
		return (1);
	return (0);
}

int		check_surrounding(int i, int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(real_map[i - 1][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index - 1))
				counter++;
		if (check_bit(real_map[i + 1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
	{
		if (check_bit(real_map[i - 1][j - 1], MAX_BIT - 1))
			counter++;
		if (check_bit(real_map[i][j - 1], MAX_BIT - 1))
				counter++;
		if (check_bit(real_map[i + 1][j - 1], MAX_BIT - 1))
			counter++;
	}

	//middle bit
	if (check_bit(real_map[i - 1][j], bit_index))
		counter++;
	if (check_bit(real_map[i + 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(real_map[i - 1][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i + 1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_data.cols - 1)
	{
		if (check_bit(real_map[i - 1][j + 1], 0))
			counter++;
		if (check_bit(real_map[i][j + 1], 0))
				counter++;
		if (check_bit(real_map[i + 1][j + 1], 0))
			counter++;
	}
	return (counter);
}

int		check_last_int_surrounding(int i, int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(real_map[i - 1][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index - 1))
				counter++;
		if (check_bit(real_map[i + 1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
	{
		if (check_bit(real_map[i - 1][j - 1], MAX_BIT - 1))
			counter++;
		if (check_bit(real_map[i][j - 1], MAX_BIT - 1))
				counter++;
		if (check_bit(real_map[i + 1][j - 1], MAX_BIT - 1))
			counter++;
	}

	//middle bit
	if (check_bit(real_map[i - 1][j], bit_index))
		counter++;
	if (check_bit(real_map[i + 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < g_data.remaining_length - 1)
	{
		if (check_bit(real_map[i - 1][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i + 1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_data.cols - 1)
	{
		if (check_bit(real_map[i - 1][j + 1], 0))
			counter++;
		if (check_bit(real_map[i][j + 1], 0))
				counter++;
		if (check_bit(real_map[i + 1][j + 1], 0))
			counter++;
	}
	return (counter);
}

int		check_top(int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(real_map[0][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
	{
		if (check_bit(real_map[0][j - 1], MAX_BIT - 1))
				counter++;
		if (check_bit(real_map[1][j - 1], MAX_BIT - 1))
			counter++;
	}

	//middle bit
	if (check_bit(real_map[1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(real_map[0][j], bit_index + 1))
				counter++;
		if (check_bit(real_map[1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_data.cols - 1)
	{
		if (check_bit(real_map[0][j + 1], 0))
				counter++;
		if (check_bit(real_map[1][j + 1], 0))
			counter++;
	}
	return (counter);
}

int		check_bottom(int i, int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(real_map[i - 1][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
	{
		if (check_bit(real_map[i - 1][j - 1], MAX_BIT - 1))
			counter++;
		if (check_bit(real_map[i][j - 1], MAX_BIT - 1))
			counter++;
	}

	//middle bit
	if (check_bit(real_map[i - 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(real_map[i - 1][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index + 1))
			counter++;
	}
	else if (j < g_data.cols - 1)
	{
		if (check_bit(real_map[i - 1][j + 1], 0))
			counter++;
		if (check_bit(real_map[i][j + 1], 0))
			counter++;
	}
	return (counter);
}
