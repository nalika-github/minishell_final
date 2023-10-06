/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:15:36 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/30 00:26:19 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	ft_strlen_size(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len = ft_strlen_size (s1) + ft_strlen_size(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	ft_memmove(str, s1, ft_strlen_size(s1));
	ft_memmove(str + ft_strlen_size(s1), s2, ft_strlen_size(s2));
	str[len - 1] = '\0';
	return (str);
}