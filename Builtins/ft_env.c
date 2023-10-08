/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:57 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/08 17:48:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_env(t_dict *new_dict)
{
	int	i;

	i = 0;
	dprintf(2, "env\n");
	// ft_prtdict(new_dict);
	while (new_dict)
	{
		if (new_dict->tmp_dict->value != NULL)
		{
			ft_putstr_fd(new_dict->tmp_dict->key, STDOUT_FILENO);
			if (new_dict->tmp_dict->value)
			{
				ft_putstr_fd("=", STDOUT_FILENO);
				ft_putstr_fd(new_dict->tmp_dict->value, STDOUT_FILENO);
			}
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		new_dict = new_dict -> next;
	}
}
