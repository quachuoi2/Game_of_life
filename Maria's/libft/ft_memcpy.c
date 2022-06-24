/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:40:32 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/20 20:04:52 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char		*p;
	char			*d;

	if (!dst && !src)
		return (0);
	d = dst;
	p = src;
	while (n--)
		*d++ = *p++;
	return (dst);
}
