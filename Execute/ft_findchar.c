/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:06:49 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/14 17:07:11 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_findchar(char *s1, char s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2)
	{
		if (s1[i] == s2)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}