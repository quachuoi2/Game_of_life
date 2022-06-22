/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 22:20:07 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void parse_line(char *line, int i)
{
	int	j = 0;
	int	bit_count = 0;

	while (*line)
	{
		g_map.map[i][j] = g_map.map[i][j] << 1 | (*line == 'x' || *line == 'X');
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
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_msg(3);

	if (get_next_line(fd, &line) == -1)
		exit_msg(2);

	i = 0;
	g_map.temp_cols = ft_strlen(line);
	g_map.cols = (g_map.temp_cols / MAX_BIT) + 1;
	while (i < g_map.lines)
	{
		g_map.map[i] = ft_memalloc(sizeof(long int) * g_map.cols);
		parse_line(line, i++);
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	g_map.name = ft_strdup(file);
	if (g_map.lines == 0)
		exit_msg(5);

	if (close(fd) == -1)
		exit_msg(4);
}
