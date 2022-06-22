/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:14:58 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 16:22:03 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	draw_test()
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map.lines)
	{
		j = 0;
		while (j < g_map.cols)
		{
			printf("%3d", g_map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
