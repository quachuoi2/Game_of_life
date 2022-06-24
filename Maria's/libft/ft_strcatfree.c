/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:34:16 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/19 10:34:53 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatfree(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	free(s2);
	return (s1);
}
