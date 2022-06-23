/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:24:42 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/24 01:10:03 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

void	create_map_a(t_map *map)
{
	uint8_t	i;

	i = 0;
	map->map_a = ft_memalloc(sizeof(long int *) * map->lines);
	while (i < map->lines)
		map->map_a[i++] = ft_memalloc(sizeof(long int) * map->cols);
}

static void	malloc_extra_line(t_map *map)
{
	int		**tmp;
	uint8_t	i;

	tmp = (int **)malloc(sizeof(int *) * (map->lines));
	ft_memcpy(tmp, map->map_g, sizeof(int **) * map->lines);
	if (map->lines)
		free(map->map_g);
	map->map_g = (int **)malloc(sizeof(int *) * (map->lines + 1));
	i = 0;
	while (i < map->lines)
	{
		map->map_g[i] = tmp[i];
		i++;
	}
	free(tmp);
}

static uint8_t	line_len(char *line)
{
	uint8_t	count;

	count = 0;
	while (line[count] != '\n' && (line[count] == '.' || line[count] == 'x' || line[count] == 'X'))
		count++;
	return (count);
}

static void	parse_state_line(char *line, t_map *map)
{
	uint8_t	i;
	uint8_t	col;

	i = 0;
	col = 0;
	map->map_g[map->lines] = (int *)malloc(sizeof(int) * map->cols);
	while (line[i])
	{
		if (line[i] == '.')
			map->map_g[map->lines][col++] = '0' - '0';
		if (line[i] == 'x' || line[i] == 'X')
			map->map_g[map->lines][col++] = '1' - '0';
		i++;
	}
	map->lines++;
}

void	parse_state(char *file, t_map *map)
{
	FILE	*f;
	char	line[BUFF_SIZE];
	uint8_t	i;

	i = 0;
	f = fopen(file, "r");
	if (f == NULL)
		exit_msg(3);

	map->cols = 0;
	map->lines = 0;
	while (fgets(line, BUFF_SIZE, f))
	{
		if (map->cols == 0)
			map->cols = line_len(line);
		malloc_extra_line(map);
		parse_state_line(line, map);
	}
	create_map_a(map);
	fclose(f);
}
