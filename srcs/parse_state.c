/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/23 18:07:51 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void parse_line(char *line, int i)
{
	int	j = 0;
	int	bit_count = 0;

	//g_map.map[i][j] = 0; //not neccessary (?) as memalloc already initialized it
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
/* 		ft_printf("%llb\n", g_map.map[i][0]);
		printf("%s\n", line); */
		i++;
		getline(&line, &size, fd);
	}
	free(line);
	g_map.name = ft_strdup(file);
	if (g_map.lines == 0)
		exit_msg(5);

	if (fclose(fd) == -1)
		exit_msg(4);
}
