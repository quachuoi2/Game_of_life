/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:25:07 by mrozhnov          #+#    #+#             */
/*   Updated: 2021/11/23 21:01:22 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((const unsigned char) *s1 == (const unsigned char) *s2 \
												&& (const unsigned char) *s1)
	{
		s1++;
		s2++;
	}
	return ((int)((const unsigned char)*s1 - (const unsigned char)*s2));
}
