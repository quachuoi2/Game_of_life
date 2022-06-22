/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:10:10 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/19 11:12:04 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_len(char const *s, char c, size_t i)
{
	size_t	l;

	l = 0;
	while (s[l + i] != '\0' && s[l + i] != c)
		l++;
	return (l);
}
