/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 22:09:34 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/03/29 18:15:37 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  The return value can be 1, 0 or -1 depending on whether a line has been
** read, when the reading has been completed, or if an error has happened
** respectively

** this function checks if the remain was already saved.
*/
static void	if_str(char **str, char **remain, char *buf)
{
	*str = ft_strchr(buf, '\n');
	if (*str)
	{
		**str = '\0';
		*remain = ft_strdup(++(*str));
	}
}

static char	*check_remain(char **remain, char **line)
{
	char	*n;

	n = 0;
	if (*remain)
	{
		n = ft_strchr(*remain, '\n');
		if (ft_strchr(*remain, '\n'))
		{
			*n = '\0';
			*line = ft_strdup(*remain);
			ft_strcpy(*remain, ++n);
		}
		else
		{
			*line = ft_strdup(*remain);
			ft_strdel(remain);
		}
	}
	else
		*line = ft_strnew(1);
	if (!*line)
		return (NULL);
	return (n);
}

/*
** this function does the main work
*/

static int	get_line(const int fd, char **line, char **remain)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*str;
	char		*temp;

	if (read(fd, remain[0], 0) < 0)
		return (-1);
	ret = 1;
	str = check_remain(remain, line);
	while (*line && !str && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if_str(&str, remain, buf);
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	if (!*line)
		return (-1);
	return (ret || ft_strlen(*line) || (*remain && ft_strlen(*remain)));
}

/*
** this function creats the new element for new fd & remain
*/

static t_gnl	*new_elem(const int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->remain = NULL;
	new->next = NULL;
	return (new);
}

/*
** first "if" checks if it is a first time we read the file, second
** "if" checks if there is a new file and
** creats a new element with get_elem function
*/

int	get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
	{
		head = new_elem(fd);
		if (!head)
			return (-1);
	}
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new_elem(fd);
			if (tmp->next == NULL)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->remain));
}
