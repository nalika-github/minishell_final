/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_bot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:18:37 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 01:34:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*ft_lstpop_bot(t_list *lst)
{
	t_list	*b4_last;

	if (ft_lstsize(lst) == 0)
		return (0);
	if (ft_lstsize(lst) == 1)
		return (lst);
	while (lst->next)
	{
		b4_last = lst;
		lst = lst->next;
	}
	b4_last->next = NULL;
	return (lst);
}
