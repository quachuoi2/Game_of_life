/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:29:33 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/23 21:09:57 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	l_s1;
	size_t	l_s2;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	ft_memcpy(s1 + l_s1, s2, l_s2);
	ft_bzero(s1 + l_s1 + l_s2, 1);
	return (s1);
}

/*
** old version:
**{
**	size_t	l;
**
**	i = 0;
**	while (*s1++])
**		l++;
**	ft_strcpy(&(s1[l]), s2);
**	return (s1);
**}
*/