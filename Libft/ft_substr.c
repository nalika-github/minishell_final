/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:48:00 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 02:23:17 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	malloc_len;

	if (start > ft_strlen(s))
		malloc_len = 0;
	else if ((ft_strlen(s) - start) >= len)
		malloc_len = len;
	else
		malloc_len = (ft_strlen(s) - start);
	str = (char *)malloc(sizeof(*s) * (malloc_len + 1));
	if (!str)
		return (0);
	i = start;
	j = 0;
	while (j < malloc_len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
