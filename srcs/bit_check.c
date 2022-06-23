/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/23 19:57:49 by qnguyen          ###   ########.fr       */
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
	if (bit_index < MAX_BIT)
	{
		if (check_bit(g_map.map[i][j], bit_index + 1))
			return (1);
	}
	else if (j > 0)
		if (check_bit(g_map.map[i][j - 1], 0))
			return (1);
	return (0);
}

int check_right_bit(int i, int j, int bit_index)
{
	if (bit_index > 0)
	{
		if (check_bit(g_map.map[i][j], bit_index - 1))
			return (1);
	}
	else if (j < g_map.cols - 2)
		if (check_bit(g_map.map[i][j + 1], MAX_BIT))
			return (1);
	else if (j == g_map.cols - 2)
		if (check_bit(g_map.map[i][j + 1], g_map.temp_cols - (g_map.cols - 1) * MAX_BIT))
			return (1);
	return (0);
}
