/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:36:15 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/03/16 12:45:58 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	int			word_start;
	int			i;
	char const	*temp;

	if (c == '\0')
		return (1);
	i = 0;
	word_start = 0;
	temp = s;
	if (i == 0 && temp[i] != c)
	{
		word_start++;
		i++;
	}
	while (temp[i] != '\0' && temp [i + 1] != '\0')
	{
		if (temp[i] == c && temp[i + 1] != c)
			word_start++;
		i++;
	}
	return ((size_t)word_start);
}
