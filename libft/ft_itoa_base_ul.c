/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:40:30 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/19 10:43:34 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(unsigned long n, int base)
{
	int	i;

	i = 0;
	while (n || !i)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	base_digit(unsigned long n, int base)
{
	char	*format;
	int		i;

	format = "0123456789ABCDEF";
	i = n % base;
	return (format[i]);
}

char	*ft_itoa_base_ul(unsigned long n, int base)
{
	int		i;
	char	*arr;

	if (base < 2 || 16 < base)
		return (NULL);
	i = ft_nbrlen_base(n, base);
	arr = ft_strnew(i);
	if (!arr)
		return (NULL);
	arr[i--] = '\0';
	while (i >= 0 && arr[i] != '-')
	{
		arr[i--] = base_digit(n, base);
		n /= base;
	}
	return (arr);
}
