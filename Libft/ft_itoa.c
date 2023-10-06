/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 02:10:03 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:46:49 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	count_space(long n)
{
	size_t	sign;
	size_t	space;

	space = 0;
	sign = (n < 0);
	if (sign == 1)
	{
		n = -n;
		space++;
	}
	while (n > 0)
	{
		n = n / 10;
		space++;
	}
	return (space);
}

static char	*gen_str(long n, size_t space)
{
	char	*str;
	size_t	i;
	size_t	sign;

	i = space;
	sign = (n < 0);
	str = malloc(sizeof(char) * (space + 1));
	if (sign == 1)
	{
		str[0] = '-';
		n = -n;
	}
	if (!str)
		return (0);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (sign == 0)
		str[0] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	space;
	char	*str;

	n = (long)n;
	if (n == 0)
	{
		str = malloc(sizeof(char) * (2));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	space = count_space(n);
	return (gen_str(n, space));
}
