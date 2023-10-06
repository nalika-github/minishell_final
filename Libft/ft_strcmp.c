/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:26:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/03 16:07:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);

}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("success : %d\n", EXIT_SUCCESS);
// 	printf("failure : %d\n", EXIT_FAILURE);
// 	printf("real : %d\n", strcmp(av[1], av[2]));
// 	printf(" : %d\n", ft_strcmp(av[1], av[2]));

// }