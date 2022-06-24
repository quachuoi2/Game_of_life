/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:06:31 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/08 17:55:45 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*start;

	node = (*alst);
	while (!!node)
	{
		start = node->next;
		(*del)(node->content, node->content_size);
		free (node);
		node = start;
	}
	*alst = NULL;
}
