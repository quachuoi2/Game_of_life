/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:19:44 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/25 12:41:06 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"
#include <time.h>

void	delay(int number_of_seconds)
{
	int		milli_seconds;
	clock_t	start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void	infinite_gaming()
{
	while(1)
	{
		draw_map(g_map.map);
		check_top_bottom_border(temp_map);
		check_the_middle_guys(temp_map);
		copy_map(g_map.map, temp_map);
		delay(250);
		printf("\e[1;1H\e[2J\n");
	}
}
