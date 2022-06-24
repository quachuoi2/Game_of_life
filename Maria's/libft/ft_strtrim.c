/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnov <mrozhnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:06:57 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/26 09:33:27 by mrozhnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*p;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_whitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (ft_whitespace(s[end]) && end >= start)
		end--;
	p = ft_strsub(s, start, end - start + 1);
	if (!p)
		return (NULL);
	return (p);
}
