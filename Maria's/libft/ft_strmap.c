/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:37:55 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/28 02:41:34 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
	{
		return (NULL);
		free(fresh);
	}
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
