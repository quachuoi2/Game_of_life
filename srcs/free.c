/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:17:08 by qnguyen           #+#    #+#             */
/*   Updated: 2022/06/23 00:26:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	free_everything()
{
	int	i = 0;
	int	j;

	while (i < g_map.lines)
		free(g_map.map[i++]);
	free(g_map.map);
	free(g_map.name);
}
