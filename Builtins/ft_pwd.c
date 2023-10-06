/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:09 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 01:55:30 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	ft_putendl_fd(char *s, int fd)
// {
// 		int	i;

// 		i = 0;
// 		if (!s)
// 			return ;
// 		while (s[i] != '\0')
// 		{
// 				write (fd, &s[i], 1);
// 				i++;
// 		}
// 		write (fd, "\n", 1);
// }

void	ft_pwd(void)
{
	char *path;

	path = getcwd(NULL, 0);
	if (!path)
		return ;
	ft_putendl_fd(path, STDOUT_FILENO);
	// printf("%s\n", path);
	free (path); //  path malloc
	// exit(0);
}