/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:21:11 by qnguyen           #+#    #+#             */
/*   Updated: 2022/07/06 15:49:25 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	join_threads(thrd_t threads[THREAD_COUNT])
{
	int i = 0;
	while (i < THREAD_COUNT)
		thrd_join(threads[i++], NULL);
}

//to be implemented
//current version takes 10x the normal speed
void	multithreading(int i)
{
	thrd_t threads[THREAD_COUNT];
	int i_temp[THREAD_COUNT];
	int thread_index = 0;
	int max_row = g_data.lines - 1;

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
	join_threads(threads);
}