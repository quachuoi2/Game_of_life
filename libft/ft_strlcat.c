/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:03:47 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/29 11:49:27 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	free_space;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (l_dst >= dstsize)
		return (dstsize + l_src);
	free_space = dstsize - 1 - l_dst;
	ft_strlcpy (&dst[l_dst], src, free_space + 1);
	return (l_dst + l_src);
}
