/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_dict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:14:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/28 23:14:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminishell.h"

void	ft_lstadd_front_dict(t_dict **lst, t_dict *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
