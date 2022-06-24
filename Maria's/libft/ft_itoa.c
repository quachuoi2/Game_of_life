/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:28:02 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/28 19:50:46 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_digits(long ln)
{
	size_t	digits;

	digits = 1;
	if (ln < 0)
	{
		digits++;
		ln = -ln;
	}
	while (ln >= 10)
	{
		digits++;
		ln /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	ln;

	ln = n;
	i = count_digits(ln);
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	while (ln >= 10)
	{
		str[i - 1] = '0' + (ln % 10);
		i--;
		ln = ln / 10;
	}
	str[i - 1] = '0' + ln;
	return (str);
}
