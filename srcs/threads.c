/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:02 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/10 18:31:29 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_threads(t_mlx *mlx)
{
	pthread_t	thread_id[THREADS];
	t_thread	thread_arr[THREADS];
	int			i;
	int			ret;

	i = 0;
	while (i < THREADS)
	{
		thread_arr[i].mlx = mlx;
		thread_arr[i].thread = i;
		ret = pthread_create(&thread_id[i], NULL, draw_fractal, &thread_arr[i]);
		if (ret)
			exit_msg(3);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(thread_id[i++], NULL);
}
