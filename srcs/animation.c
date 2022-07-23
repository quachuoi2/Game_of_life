/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/07/24 00:36:23 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"
#include <time.h>

t_map	g_data;
int		**real_map;
int		**temp_map;

void	delay(int number_of_seconds)
{
	int		milli_seconds;
	clock_t	start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void	infinite_gaming(int i)
{
	while(i)
	{
		draw_map(real_map);
		check_top_bottom_border(temp_map);
		check_the_middle_guys(temp_map);
		copy_map(real_map, temp_map);
		delay(250);
		printf("\e[1;1H\e[2J\n");
		i--;
	}
	draw_map(real_map);
}

void	exit_msg(int code)
{
	if (!code)
		printf("Error\n");
	if (code == 2)
		printf("Error: stack_overflow\n");
	if (code == 3)
		printf("Error: open_file error\n");
	if (code == 4)
		printf("Error: close_file error\n");
	if (code == 5)
		printf("Error: map_error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	g_data.lines = atoi(argv[2]);
	real_map = ft_memalloc(sizeof(*real_map) * g_data.lines);
	parse_state(argv[1]);
	create_temp_map(temp_map, real_map);
	copy_map(temp_map, real_map);
	if (argc > 3)
		infinite_gaming(atoi(argv[3]));
	else
		infinite_gaming(-1);
	return (0);
}
