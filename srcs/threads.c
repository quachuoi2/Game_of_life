/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:02 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 23:55:03 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	adjasment9_threads(t_map *map)
{
	pthread_t	thread_id[THREADS];
	t_map9		*map9;

	// t_thread	thread_arr;
	int			i;
	int			ret;
	int			step;
	int			j_max_t;

	step = (map->j_max - 1) / THREADS;


	i = 0;
	while (i <= THREADS)
	{
		if (i == THREADS)
			j_max_t = map->j_max;
		else
			j_max_t = (i + 1) * step;
		printf("  %d", i*step+1);
		printf("  %d\n", j_max_t);
		map9 = &(t_map9){map, i * step + 1, j_max_t};
		ret = pthread_create(&thread_id[i], NULL, adjasment_9, map9);
		if (ret)
			exit_msg(6);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thread_id[i++], NULL);
}

