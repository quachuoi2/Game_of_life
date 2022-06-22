/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:27:13 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/24 15:20:25 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *) dst;
	s = (char *) src;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if ((unsigned char) s[i] == (unsigned char) c)
			return (&(dst[i + 1]));
		i++;
	}
	return (NULL);
}
