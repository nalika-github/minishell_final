/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinextra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:13:12 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/30 00:28:56 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strjoinextra(char *str1, char *str2, int nbr_free)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str1[++i])
		res[i] = str1[i];
	i = i - 1;
	j = -1;
	while (str2[++j])
		res[++i] = str2[j];
	res[++i] = '\0';
	if (nbr_free == BEFORE)
		free (str1);
	if (nbr_free == AFTER)
		free (str2);
	if (nbr_free == BEFOREANDAFTER)
	{
		free (str1);
		free (str2);
	}
	// printf("finish_strjoinextra\n");
	// exit(0);
	return (res);
}
