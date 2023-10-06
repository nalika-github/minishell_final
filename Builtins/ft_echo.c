/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:52 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/04 02:14:31 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(char **cmd, int fd_out)
{
	int	i;
	int	no_nl;

	i = 1;
	no_nl = 0;
	if (cmd[1] == NULL)
	{
		ft_putstr_fd("\n", fd_out);
		return ;
	}
	if (ft_findstr(cmd[1], "-n", 2) == EXIT_SUCCESS)
	{
		no_nl = 1;
		i = 2;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], fd_out);
		i++;
		if (!cmd[i])
			break ;
		ft_putstr_fd(" ", fd_out);
	}
	if (no_nl == 0)
		write(fd_out, "\n", 1);
}
