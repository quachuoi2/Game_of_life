/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:28 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/28 02:32:33 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*s1;
	char		*s2;
	size_t		i;
	size_t		l1;
	size_t		l2;

	s1 = (char *) haystack;
	s2 = (char *) needle;
	l1 = ft_strlen(haystack);
	l2 = ft_strlen(needle);
	i = 0;
	if (*s2 == '\0')
		return (s1);
	if (l2 > l1)
		return (NULL);
	while (i <= l1 - l2)
	{
		if (ft_strncmp(&(haystack[i]), needle, l2) == 0)
			return (&(s1[i]));
		i++;
	}
	return (NULL);
}
