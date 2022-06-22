/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 18:52:16 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

// static void	init_map_a(t_map *map)
// {
// 	int		i;

// 	i = 0;
// 	map->map_a = (t_map **)malloc(sizeof(int *) * map->lines + 1);
// 	while (i < map->lines)
// 	{
// 		map->map_a[i] = (t_map *)malloc(sizeof(int) * map->cols);
// 		i++;
// 	}
// }

static void	malloc_extra_line(t_map *map)
{
	int	**tmp;
	int	**tmp_a;
	int	i;

	tmp = (int **)malloc(sizeof(int *) * (map->lines));
	tmp_a = (int **)malloc(sizeof(int *) * (map->lines));
	ft_memcpy(tmp, map->map, sizeof(int **) * map->lines);
	ft_memcpy(tmp_a, map->map_a, sizeof(int **) * map->lines);
	if (map->lines)
		free(map->map);
	map->map = (int **)malloc(sizeof(int *) * (map->lines + 1));
	map->map_a = (int **)malloc(sizeof(int *) * (map->lines + 1));
	i = 0;
	while (i < map->lines)
	{
		map->map[i] = tmp[i];
		map->map_a[i] = tmp_a[i];
		i++;
	}
	free(tmp);
}

static int	line_len(char *line)
{
	int	count;

	count = 0;
	while (line[count] == '.' || line[count] == 'x' || line[count] == 'X')
			count++;
	return (count);
}

static void	parse_state_line(char *line, t_map *map)
{
	int	i;
	int	col;
	int	len;

	i = 0;
	col = 0;
	len = line_len(line);
	map->map[map->lines] = (int *)malloc(sizeof(int) * len);
	map->map_a[map->lines] = (int *)malloc(sizeof(int) * len);
	while (line[i])
	{
		if (line[i] == '.')
			map->map[map->lines][col++] = '0' - '0';
		if (line[i] == 'x' || line[i] == 'X')
			map->map[map->lines][col++] = '1' - '0';
		i++;
	}
	map->lines++;
	map->cols = col;
}

void	parse_state(char *file, t_map *map)
{
	int		fd;
	char	*line;

	map->name = ft_strdup(file); // to decide later
	map->lines = 0;
	map->cols = 0;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_msg(3);
	while (get_next_line(fd, &line) > 0)
	{
		malloc_extra_line(map);
		parse_state_line(line, map);
		if (!line)
			exit_msg(2);
		free(line);
	}
	if (map->lines == 0)
		exit_msg(5);
	if (close(fd) == -1)
		exit_msg(4);
}
