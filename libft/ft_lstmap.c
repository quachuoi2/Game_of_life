/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozhnova <mrozhnova@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:06:34 by mrozhnova         #+#    #+#             */
/*   Updated: 2022/02/08 16:59:31 by mrozhnova        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t contentsize)
{
	if (content != NULL)
	{
		free(content);
		content = NULL;
	}
	contentsize = 0;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	result = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
	if (!result)
		return (NULL);
	start = result;
	while (!!lst->next)
	{
		lst = lst->next;
		result->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!result->next)
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		result = result->next;
	}
	return (start);
}
