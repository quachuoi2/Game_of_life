/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:12:29 by mrozhnova         #+#    #+#             */
/*   Updated: 2021/11/21 22:34:05 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	while (*s)
		ft_bzero((void *)s, l);
}
