/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:39:12 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/23 23:16:41 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_findstr(char *str, char *find, int len)
{
	int	i;

	i = 0;
	while (find[i] == str[i])
	{
		i++;
		if (i == len && str[i] == '\0')
			return(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("sucess : %d\n", EXIT_SUCCESS);
// 	printf("failure : %d\n", EXIT_FAILURE);
// 	// printf("av[1] : %s\n", av[1]);
// 	printf("res : %d\n", ft_findstr(av[1], "~", 1));

// }