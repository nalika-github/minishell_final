/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:09 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 06:22:21 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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