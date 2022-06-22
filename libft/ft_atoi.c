/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:43:19 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/28 19:39:48 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_overflow(int sign)
{
	long	max;
	long	min;

	max = (2 >> 31) - 1;
	min = (-2 >> 31) + 1;
	if (sign > 0)
		return ((int) max);
	else
		return ((int) min);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			return (int_overflow(sign));
		i++;
	}
	return ((int)(res * sign));
}
