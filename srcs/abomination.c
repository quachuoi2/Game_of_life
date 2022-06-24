/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abomination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/24 03:29:21 by qnguyen          ###   ########.fr       */
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

	//check bits on the row above
		//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i - 1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[i - 1][j - 1], MAX_BIT - 1))
			counter++;

	//middle bit
	if (check_bit(g_map.map[i - 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i - 1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i - 1][j + 1], 0))
			counter++;

	//check bits on the row below
	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i + 1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[i + 1][j - 1], MAX_BIT - 1))
			counter++;

	//middle bit
	if (check_bit(g_map.map[i + 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i + 1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i + 1][j + 1], 0))
			counter++;

	if (counter > 3)
		return (-1);

	//check current row
	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i][j], bit_index - 1))
				counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[i][j - 1], MAX_BIT - 1))
				counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i][j], bit_index + 1))
				counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i][j + 1], 0))
				counter++;

	return (counter);
}

int		check_top(int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[1][j - 1], MAX_BIT - 1))
			counter++;

	//middle bit
	if (check_bit(g_map.map[1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[1][j + 1], 0))
			counter++;

	//check current row
	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[0][j], bit_index - 1))
				counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[0][j - 1], MAX_BIT - 1))
				counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[0][j], bit_index + 1))
				counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[0][j + 1], 0))
				counter++;

	return (counter);
}

int		check_bottom(int i, int j, int bit_index)
{
	register int counter = 0;

	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i - 1][j], bit_index - 1))
			counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[i - 1][j - 1], MAX_BIT - 1))
			counter++;

	//middle bit
	if (check_bit(g_map.map[i - 1][j], bit_index))
		counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i - 1][j], bit_index + 1))
			counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i - 1][j + 1], 0))
			counter++;

	//check current row
	//left bit
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i][j], bit_index - 1))
				counter++;
	}
	else if (j > 0)
		if (check_bit(g_map.map[i][j - 1], MAX_BIT - 1))
				counter++;

	//right bit
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i][j], bit_index + 1))
				counter++;
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i][j + 1], 0))
				counter++;

	return (counter);
}
