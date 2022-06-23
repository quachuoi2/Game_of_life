/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/24 00:00:18 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

int		check_bit(long int num, int n)
{
	if (num & (1 << n))
		return (1);
	return (0);
}

int check_left_bit(int i, int j, int bit_index)
{
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i][j], bit_index - 1))
			return (1);
	}
	else if (j > 0)
		if (check_bit(g_map.map[i][j - 1], MAX_BIT - 1))
			return (1);
	return (0);
}

int check_right_bit(int i, int j, int bit_index)
{
	if (bit_index < MAX_BIT - 1)
	{
		if (check_bit(g_map.map[i][j], bit_index + 1))
			return (1);
	}
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i][j + 1], 0))
			return (1);
	return (0);
}

int		check_surrounding(int i, int j, int bit_index)
{
	int counter = 0;

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
	if (counter > 3)
		return (-1);
	//check current row
	if (check_left_bit(i, j, bit_index))
		counter++;
	if (check_right_bit(i, j, bit_index))
		counter++;
	return (counter);
}