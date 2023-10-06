/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_dict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:04:13 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/17 02:04:17 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstadd_front_dict(t_dict **lst, t_dict *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
