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

void	check_top_bottom_border()
{
	int j = 0;
	int last_row = g_map.lines - 1;
	while (j < g_map.cols)
	{
		int bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			register int top_surrounding = check_top(j, bit_index);
			register int bot_surrounding = check_bottom(last_row, j, bit_index);

			if (check_bit(g_map.map[0][j], bit_index))
			{
				if (top_surrounding != 2 && top_surrounding != 3)
					temp_map[0][j] &= ~(1 << bit_index);
			}
			else if (top_surrounding == 3)
				temp_map[0][j] |= 1 << bit_index;

			if (check_bit(g_map.map[last_row][j], bit_index))
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
}

int	check_line(void *i)
{
	int	j = 0;
	while (j < g_map.cols)
	{
		int bit_index = 0;
		while (bit_index < MAX_BIT)
		{
			int surrounding = check_surrounding(*(int *)i, j, bit_index);
			if (check_bit(g_map.map[*(int *)i][j], bit_index))
			{
				if (surrounding != 2 && surrounding != 3)
					temp_map[*(int *)i][j] &= ~(1 << bit_index);
			}
			else if (surrounding == 3)
				temp_map[*(int *)i][j] |= 1 << bit_index;
			bit_index++;
		}
		j++;
	}
	return (0);
}

void	join_threads(thrd_t threads[THREAD_COUNT])
{
	int i = 0;
	while (i < THREAD_COUNT)
		thrd_join(threads[i++], NULL);
}

void	check_the_middle_guys()
{
	int	i = 1;
	int max_row = g_map.lines - 1;

	while (i < max_row)
	{
		/* thrd_t threads[THREAD_COUNT];
		int i_temp[THREAD_COUNT];
		int thread_index = 0;
		while (thread_index < THREAD_COUNT)
		{
			i_temp[thread_index] = i;
			if (i_temp[thread_index] == max_row)
			{
				join_threads(threads);
				return ;
			}
			thrd_create(&threads[thread_index], check_line, &i_temp[thread_index]);
			thread_index++;
			i++;
		}
		join_threads(threads); */
		check_line(&i);
		i++;
	}
}

void	play_n_turn(char *turn)
{
	int i = ft_atoi(turn);
	while (i--)
	{
		//why does this work?
		check_top_bottom_border(temp_map);
		check_the_middle_guys(temp_map);
		//and is faster than this
		//check_top_bottom_border();
		//check_the_middle_guys();
		copy_map(g_map.map, temp_map);
	}
	draw_map(g_map.map);
}
