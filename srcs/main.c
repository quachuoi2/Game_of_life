/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:14:00 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/06/22 16:40:34 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/life.h"

t_map	g_map;

void	exit_msg(int code)
{
	if (!code)
		write(1, "Error\n", 6);

//	can be removed because the same check is in the shell script
	if (code == 1)
		write(1, "Error: add the 1 argument\n", 27);

	if (code == 2)
		write(1, "Error: stack_overflow\n", 23);
	if (code == 3)
		write(1, "Error: open_file error\n", 23);
	if (code == 4)
		write(1, "Error: close_file error\n", 23);
	if (code == 5)
		write(1, "Error: map_error\n", 23);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		line_count_fd;
	char	*line_count;

	if (argc != 3) //change to 3
		exit_msg (1);

	//open the line_count file
	line_count_fd = open("line_count", O_RDONLY);
	if (line_count_fd == -1)
		exit_msg(3);

	//read the first (and only) line
	if (get_next_line(line_count_fd, &line_count) == -1)
		exit_msg(1);

	//close it
	if (close(line_count_fd) == -1)
		exit_msg(4);

	//convert the text to number and assign that number to map.lines
	g_map.lines = ft_atoi(line_count);
	g_map.map = (int **)ft_memalloc(sizeof(int *) * g_map.lines);
	free(line_count);

	parse_state(argv[1]);
	draw_test();
	// handle_image(map);
	return (0);
}
