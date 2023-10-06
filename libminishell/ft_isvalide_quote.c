/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalide_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:31 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/28 23:21:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminishell.h"

int	ft_isvalide_quote(char *str)
{
	int		i;
	char	quote;

	quote = str[0];
	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			return (1);
		i++;
	}
	return(0);
}
