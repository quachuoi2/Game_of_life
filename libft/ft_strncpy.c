/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:05:12 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/03/16 12:45:14 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	x;

	x = 0;
	while (src[x] != '\0' && n > x)
	{
		dest[x] = src[x];
		x++;
	}
	while (n > x)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}
