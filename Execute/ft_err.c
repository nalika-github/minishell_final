/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:37:43 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/04 02:02:59 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_prterr_builtins(int mode, char *cmd, char *str, int err)
{

	if (mode == PER_DN)
		printf("bash: %s: %s: No such file or directory\n" ,cmd, str);
	else if (mode == CANNT_OPEN)
		printf("bash: %s: %s: Permission denied\n" ,cmd, str);
	// exit (err); // ??
}
void	ft_prterrexec(char *str, int errno, int mode)
{
	(void)errno;
	// dprintf(2, "hello1\n");
	if (mode == ERR_PATH)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (mode == NO_FILE)
	{
		// dprintf(2, "Hello_print\n");
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (mode == PER_FILE)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (mode == ERR_CMD)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found\n", 2);
	}


}

// void	ft_prterrexec(char *str, int errno, int mode)
// {
// 	(void)errno;
// 	if (mode == ERR_PATH)
// 	{
// 		// printf("err : %s\n" , path[0]);
// 		ft_putstr_fd("bash: ", 2);
// 		ft_putstr_fd(str, 2);
// 		ft_putstr_fd(": No such file or directory\n", 2);
// 		// exit(0);
// 	}
// 	else if (mode == CANNT_OPENIN)
// 	{
// 		ft_putstr_fd("bash: ", 2);
// 		ft_putstr_fd(str , 2);
// 		ft_putstr_fd(": Permission denied\n", 2);
// 		// exit(0);
// 	}
// 	else if (mode == CANNT_OPENOUT)
// 	{
// 		ft_putstr_fd("bash: ", 2);
// 		ft_putstr_fd(str , 2);
// 		ft_putstr_fd(": Permission denied\n", 2);
// 		// exit(0);
// 	}
// }

void	ft_prterr(int mode, char *txt)
{
	dprintf(2, "ft_prterr\n");
	if (mode == CANNT_PIPE)
		ft_putstr_fd("It can't create pipe", 2);
	else if (mode == CANNT_FORK)
		ft_putstr_fd("It can't fork", 2);
	else if (mode == CANNT_OPENIN)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(txt , 2);
		ft_putstr_fd(": Permission denied\n", 2);
		// exit(0);
	}
	else if (mode == CANNT_OPENOUT)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(txt , 2);
		ft_putstr_fd(": Permission denied\n", 2);
		// exit(0);
	}
	// exit();??
}