/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:17:36 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 01:34:38 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_node;
	t_list	*new_lst;

	if (!lst || !del || !f)
		return (0);
	new_lst = ft_lstnew(f(lst->data));
	begin_node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->data));
		ft_lstadd_back(&begin_node, new_lst);
		if (!new_lst)
		{
			ft_lstclear(&begin_node, del);
		}
		lst = lst->next;
	}
	return (begin_node);
}
