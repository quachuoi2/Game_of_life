/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:28:00 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/05/19 10:47:41 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (src[l] != '\0')
		l++;
	temp = (char *)malloc(sizeof(char) * (l + 1));
	if (!temp)
		return (NULL);
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
