/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:06:17 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/02 17:49:38 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char fresh))
{
	char			*fresh;
	unsigned int	i;
	size_t			l;

	i = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	fresh = ft_strnew(l);
	if (!fresh)
		return (NULL);
	while (i != l)
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
