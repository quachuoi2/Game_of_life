/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:02 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 21:00:12 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	adjasment9_threads(t_mlx *mlx)
{
	pthread_t	thread_id[THREADS];
	t_thread	thread_arr;
	int			i;
	int			ret;

	i = 0;
	while (i < THREADS)
	{
		// thread_arr.map = map;
		thread_arr.thread = i;
		ret = pthread_create(&thread_id[i], NULL, adjasment_9, thread_arr);
		if (ret)
			exit_msg(6);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thread_id[i++], NULL);
}
