/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:56:08 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/23 20:17:30 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	char	*s;

	s = (char *) src;
	len = ft_strlen(s);
	if (dstsize < 1)
		return (len);
	i = 0;
	while (s[i] && i < dstsize - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
