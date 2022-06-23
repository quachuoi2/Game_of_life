/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 00:26:56 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void parse_line(char *line, int i)
{
	int	j = 0;
	int	bit_count = 0;

	while (*line != '\n')
	{
		if (*line == 'x' || *line == 'X')
			g_map.map[i][j] ^= 1UL << bit_count;
		if (bit_count < MAX_BIT - 1)
			bit_count++;
		else
		{
			j++;
			bit_count = 0;
		}
		line++;
	}
}

void	parse_state(char *file)
{
	FILE 	*fd;
	int		i;
	size_t	size = 420;
	char	*line = ft_memalloc(sizeof(line) * size);

	fd = fopen(file, "r");

	g_map.temp_cols = getline(&line, &size, fd) - 1;
	if (g_map.temp_cols < 0)
		exit_msg(2);

	i = 0;
	g_map.cols = (g_map.temp_cols / MAX_BIT) + 1;
	while (i < g_map.lines)
	{
		g_map.map[i] = ft_memalloc(sizeof(long int) * g_map.cols);
		parse_line(line, i);
		i++;
		getline(&line, &size, fd);
	}
	free(line);
	if (g_map.lines == 0)
		exit_msg(5);

	if (fclose(fd) == -1)
		exit_msg(4);
}
