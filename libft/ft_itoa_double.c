/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:37:26 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/05/19 10:44:23 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_doublelen(long n, int precision)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + precision + 1);
}

static int	ft_ulonglen(unsigned long n)
{
	int	i;

	i = 0;
	while (n || !i)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	power_10(int power)
{
	int	i;

	i = 10;
	while (power-- > 1)
		i *= 10;
	return (i);
}

static void	handle_rounding(unsigned long *n, long double *d, int precision)
{
	int	i;
	int	len;

	i = 0;
	while (i++ < precision)
		*d *= 10;
	if (((unsigned long)(*d * 10) % 10) > 4)
	{
		len = ft_ulonglen((unsigned long)*d);
		(*d)++;
		if ((ft_ulonglen((unsigned long)*d) != len && \
			(unsigned long) *d % power_10(precision) == 0) || !precision)
		{
			(*n)++;
			*d = 0;
		}
	}
}

char	*ft_itoa_double(long double d, int precision)
{
	int				i;
	unsigned long	n;
	char			*arr;

	i = ft_doublelen(d, precision);
	arr = ft_strnew(i);
	if (d < 0)
	{
		ft_strcpy(arr, "-");
		d *= -1;
	}
	n = (unsigned long)d;
	d -= (unsigned long)d;
	handle_rounding(&n, &d, precision);
	ft_strcatfree(arr, ft_itoa_base_ul(n, 10));
	if (precision > 0)
	{
		ft_strcat(arr, ".");
		precision -= ft_ulonglen((unsigned long)d);
		while (precision-- > 0)
			ft_strcat(arr, "0");
		ft_strcatfree(arr, ft_itoa_base_ul((unsigned long)d, 10));
	}
	return (arr);
}
