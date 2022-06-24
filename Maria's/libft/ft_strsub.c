/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:38:57 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/03/16 12:50:41 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;

	if (!s)
		return (NULL);
	fresh = ft_strnew(len);
	if (!fresh)
		return (NULL);
	ft_strncpy(fresh, &(s[start]), len);
	fresh[len] = '\0';
	return (fresh);
}
