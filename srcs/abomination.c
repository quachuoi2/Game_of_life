/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abomination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/07/06 15:39:15 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

int		check_bit(int num, int n)
{
	return (num & (1 << n));
}

int		check_surrounding(int i, int j, int bit_index, int last_int)
{
	register int counter = 0;
	int right_side_length = (last_int ? g_data.remaining_length : MAX_BIT) - 1;

	//left bit
	if (bit_index > 0)
	{
		// Why does passing values around and returning go even faster than without
		if (check_bit(real_map[i - 1][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index - 1))
			counter++;
		if (check_bit(real_map[i + 1][j], bit_index - 1))
			counter++;
		// why is this slower than calling an extra function?
		/* if (real_map[i - 1][j] & (1 << bit_index - 1))
			counter++;
		if (real_map[i][j] & (1 << bit_index - 1))
			counter++;
		if (real_map[i + 1][j] & (1 << bit_index - 1))
			counter++; */
	}
	else if (j > 0)
	{
		if (check_bit(real_map[i - 1][j - 1], MAX_BIT - 1))
			counter++;
		if (check_bit(real_map[i][j - 1], MAX_BIT - 1))
			counter++;
		if (check_bit(real_map[i + 1][j - 1], MAX_BIT - 1))
			counter++;
		/* if (real_map[i - 1][j - 1] & (1 << MAX_BIT - 1))
			counter++;
		if (real_map[i][j - 1] & (1 << MAX_BIT - 1))
			counter++;
		if (real_map[i + 1][j - 1] & (1 << MAX_BIT - 1))
			counter++; */
	}

	//middle bit
	if (check_bit(real_map[i - 1][j], bit_index))
		counter++;
	if (check_bit(real_map[i + 1][j], bit_index))
		counter++;
	/* if (real_map[i - 1][j] & (1 << bit_index))
		counter++;
	if (real_map[i + 1][j] & (1 << bit_index))
		counter++; */

	//right bit
	if (bit_index < right_side_length)
	{
		if (check_bit(real_map[i - 1][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i][j], bit_index + 1))
			counter++;
		if (check_bit(real_map[i + 1][j], bit_index + 1))
			counter++;
		/* if (real_map[i - 1][j] & (1 << bit_index + 1))
			counter++;
		if (real_map[i][j] & (1 << bit_index + 1))
			counter++;
		if (real_map[i + 1][j] & (1 << bit_index + 1))
			counter++; */
	}
	else if (j < g_data.cols - 1)
	{
		if (check_bit(real_map[i - 1][j + 1], 0))
			counter++;
		if (check_bit(real_map[i][j + 1], 0))
			counter++;
		if (check_bit(real_map[i + 1][j + 1], 0))
			counter++;
/* 		if (real_map[i - 1][j + 1] & 1)
			counter++;
		if (real_map[i][j + 1] & 1)
			counter++;
		if (real_map[i + 1][j + 1] & 1)
			counter++; */
	}
	return (counter);
}


int		check_top_bottom_surrounding(int i, int j, int bit_index, int last_int)
{
	register int counter = 0;
	int right_side_length = (last_int ? g_data.remaining_length : MAX_BIT) - 1;

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
	if (bit_index < right_side_length)
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
