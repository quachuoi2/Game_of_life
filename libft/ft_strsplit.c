/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:10:43 by mrozhnov          #+#    #+#             */
/*   Updated: 2022/02/08 17:54:14 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_delsarr(char **sarray, int count)
{
	while (count--)
		free (sarray[count]);
	free (sarray);
	return (NULL);
}

static int	ft_split(char const *s, char c, size_t i, char **sarray)
{
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		sarray[count] = (char *)malloc(sizeof(char) * ft_count_len(s, c, i));
		if (!sarray)
			return ((int)(long)ft_delsarr(sarray, count));
		while (s[i] && s[i] != c)
			sarray[count][j++] = s[i++];
		while (s[i] == c)
			i++;
		sarray[count][j] = '\0';
		count++;
	}
	sarray[count] = NULL;
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**sarray;
	size_t	words;

	i = 0;
	words = ft_count_words(s, c);
	sarray = (char **)malloc(sizeof(char *) * (words + 1));
	if (!sarray)
	{
		return (ft_delsarr(sarray, i));
		return (NULL);
	}
	ft_split(s, c, i, sarray);
	return (sarray);
}
