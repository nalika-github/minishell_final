/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_dict.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:09:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/01 23:46:45 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dict	*ft_lstlast_dict(t_dict *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}


// void	ft_lstadd_back(t_list **lst, t_list *new)
void	ft_lstadd_back_dict(t_dict **lst, t_dict *new)
{
	t_dict	*last;

	// dprintf(2, "c1\n");
	if (!lst || !new)
		return ;
	// dprintf(2, "c2\n");
	if (*lst)
	{
		// dprintf(2, "c3\n");
		last = ft_lstlast_dict(*lst);
		// dprintf(2, "c4\n");
		last->next = new;
		// dprintf(2, "c5\n");
	}
	else
		*lst = new;
	// dprintf(2, "c6\n");
}
