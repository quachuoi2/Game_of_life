/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:58:23 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/23 20:42:57 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	l;

	i = 0;
	l = ft_strlen(s2);
	while (s1[i])
		i++;
	if (l > n)
		l = n;
	ft_strncpy(&(s1[i]), s2, l);
	s1[i + l] = '\0';
	return (s1);
}
