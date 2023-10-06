/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_allsp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:29:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 01:35:22 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	cell_count(char const *s)
{
	size_t	touch;
	size_t	n;
	size_t	i;

	touch = 0;
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (touch == 0 && !ft_isspace(s[i]))
		{
			n++;
			touch = 1;
		}
		else if (ft_isspace(s[i]))
			touch = 0;
		i++;
	}
	return (n);
}

static	size_t	sub_strlen(char const *s, size_t index)
{
	size_t	i;

	i = 0;
	while (!ft_isspace(s[index + i]) && s[index + i] != '\0')
		i++;
	return (i);
}

static void	cell_input(char const *s, size_t index, char **cell)
{
	size_t	i;

	i = 0;
	while (!ft_isspace(s[index + i]) && s[index + i] != 0)
	{
		(*cell)[i] = s[index + i];
		i++;
	}
	(*cell)[i] = '\0';
}

char	**ft_split_allsp(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	sub_len;
	char	**split;

	split = ft_calloc((cell_count(s) + 1), sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]))
		{
			sub_len = sub_strlen(s, i);
			split[j] = ft_calloc(sub_len + 1, sizeof(char));
			cell_input(s, i, &split[j]);
			i = i + sub_len - 1;
			j++;
		}
		i++;
	}
	return (split);
}
