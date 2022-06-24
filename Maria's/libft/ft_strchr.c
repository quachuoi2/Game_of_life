/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:03:00 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/21 22:32:13 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	char	*s;

	ch = (char) c;
	s = (char *) str;
	while (*s != ch)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
