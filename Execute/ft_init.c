/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:57:46 by nkietwee          #+#    #+#             */
/*   Updated: 2023/07/11 18:08:52 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// int ft_findbuitin(char *str, char **env)
// {
// 	// printf("find\n");
// 	if (ft_findstr(str, "echo", 4) == EXIT_SUCCESS)
// 		printf("--echo--\n");
// 		// ft_echo();
// 	if (ft_findstr(str, "cd", 2) == EXIT_SUCCESS)
// 		ft_cd ("-");
// 	if (ft_findstr(str, "pwd", 3) == EXIT_SUCCESS)
// 		ft_pwd();
// 	if (ft_findstr(str, "export", 6) == EXIT_SUCCESS)
// 		printf("--export--\n");
// 	if (ft_findstr(str, "unset", 5) == EXIT_SUCCESS)
// 		printf("--unset--\n");
// 	// if (ft_findstr(str, "env", 3) == EXIT_SUCCESS)
// 	// 	ft_env(env);
// 		// printf("--env--\n");
// 	if (ft_findstr(str, "exit", 4) == EXIT_SUCCESS)
// 		printf("--exit--\n");

// 	return (EXIT_SUCCESS);
// }

int ft_main(char *find ,char **env)
{

	// ft_heredoc();
	ft_findbuitin(find, env);
	// printf("main\n");
	return (EXIT_SUCCESS);
}
