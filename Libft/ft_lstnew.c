/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:25:42 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/17 02:02:54 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->next = 0;
	lst->data = data;
	return (lst);
}

// t_dict	*ft_lstnew(void *content)
// {
// 	t_dict	*new;

// 	new = (t_dict *)malloc(sizeof(t_dict));
// 	if (!new)
// 		return (NULL);
// 	new -> content = content;
// 	new -> next = NULL;
// 	return (new);
// }
