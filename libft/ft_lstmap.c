/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:18:14 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/26 20:41:13 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = malloc(ft_lstsize(lst) * sizeof(t_list));
	if (!new_lst)
		return (NULL);
	while (lst != NULL)
	{
		new_lst->content = f(lst->content);
		new_lst->next = lst->next;
		if (del)
			del(lst->content);
		lst = new_lst->next;
	}
	ft_lstclear(&lst, del);
	return (new_lst);
}
