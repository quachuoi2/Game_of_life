/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:28 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/23 15:02:41 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

int check_left_bit(int i, int j, int bit_index)
{
	if (bit_index < 8)
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
	else if (j < g_map.cols - 1)
		if (check_bit(g_map.map[i][j + 1], 8))
			return (1);
	return (0);
}
