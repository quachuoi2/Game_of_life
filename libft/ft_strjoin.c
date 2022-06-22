/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:45:35 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/03/16 12:36:37 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	i = 0;
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!fresh)
		return (NULL);
	while (*s1)
	{
		fresh[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
