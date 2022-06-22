/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 16:31:05 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

static void parse_line(char *line, int i)
{
	int	j;

	j = 0;
	while (line[j])
	{
		g_map.map[i][j] = (line[j] == 'x' || line[j] == 'X');
		j++;
	}
}

void	parse_state(char *file)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_msg(3);

	if (get_next_line(fd, &line) == -1)
		exit_msg(2);

	i = 0;
	len = ft_strlen(line);
	while (*line)
	{
		g_map.map[i] = ft_memalloc(len * sizeof(int));
		parse_line(line, i++);
		free(line);
		get_next_line(fd, &line);
	}

	g_map.name = ft_strdup(file);
	g_map.cols = len;

	if (g_map.lines == 0)
		exit_msg(5);

	if (close(fd) == -1)
		exit_msg(4);
}
