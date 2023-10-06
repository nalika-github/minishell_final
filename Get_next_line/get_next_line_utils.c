/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:07:18 by nkietwee          #+#    #+#             */
/*   Updated: 2023/08/14 16:39:46 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_mystrjoin(char *dst, char *src)
{
	int		i;
	int		dstlen;
	int		srclen;
	char	*ans;

	i = 0;
	dstlen = ft_strlenmode(dst, 0);
	srclen = ft_strlenmode(src, 0);
	ans = (char *)malloc(sizeof(char) * (dstlen + srclen + 1));
	while (dst[i] != '\0')
	{
		ans[i] = dst[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		ans[dstlen + i] = src[i];
		i++;
	}
	ans[dstlen + i] = '\0';
	free(dst);
	return (ans);
}
