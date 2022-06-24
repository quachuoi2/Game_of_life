/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:38:37 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/28 00:55:04 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
