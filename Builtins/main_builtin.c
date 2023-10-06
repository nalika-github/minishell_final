/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:58:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/01 17:00:08 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
// echo
// cd
// pwd
export
unset
// env
exit
*/

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

// void	ft_buildin_parent(char **cmd, char  **env)
// {
// 	if (ft_findstr(cmd[0], "export", 6) == EXIT_SUCCESS)
// 		ft_export(cmd, env);
// 	else if (ft_findstr(cmd[0], "cd", 2) == EXIT_SUCCESS)
// 		ft_cd(cmd);
// 	// else if (ft_findstr(cmd[0], "unset", 5) == EXIT_SUCCESS)
// 	// 	ft_unset(cmd);
// 	// else if (ft_findstr(cmd[0], "exit", 4) == EXIT_SUCCESS)
// 	// 	ft_exit(cmd);


// 	// else if (ft_findstr(tmp[0], "env", 3) == EXIT_SUCCESS)
// 	// 	ft_env(data);
// 	// else if (ft_findstr(tmp[0], "echo", 4) == EXIT_SUCCESS)
// 	// 	ft_echo(tmp);
// 	// else if (ft_findstr(av[1], "export", 6) == EXIT_SUCCESS)

// 	// else if (ft_findstr(tmp[0], "pwd", 3) == EXIT_SUCCESS)
// 	// 	ft_pwd();
// }

// void	ft_buildin_child(char **cmd, char  **env, int fd_out)
// {
// 	// dprintf(2, "ft_buildin_child\n");
// 	// printf("cmd : %s\n", cmd[0]);
// 	if (ft_strcmp(cmd[0], "pwd") == 0)
// 		ft_pwd();
// 	else if (ft_strcmp(cmd[0], "echo") == 0)
// 		ft_echo(cmd, fd_out);
// 	else if (ft_strcmp(cmd[0], "export") == 0)
// 		ft_export(cmd, env);
// 	// else if (ft_strcmp(cmd[0], "env") == 0)
// 	// 	ft_env(data);

// 	// exit(0);
// }

// void	ft_buildin(char **av, t_data *data, char **env)
// {
// 	char	**tmp=NULL;

// 	// tmp = ft_split(av, ' ');
// 	// printf("tmp[0] : %s\n" , tmp[0]);
// 	// printf("tmp[1] : %s\n" , tmp[1]);
// 	// tmp
// 	/*edit tmp[1] -> tmp*/

// 	printf("fn\n");
// 	//fixed av[1]
// 	// if (ft_findstr(tmp[0], "cd", 2) == EXIT_SUCCESS)
// 	// 	ft_cd(tmp[1]);
// 	// else if (ft_findstr(tmp[0], "pwd", 3) == EXIT_SUCCESS)
// 	// 	ft_pwd();
// 	// else if (ft_findstr(tmp[0], "env", 3) == EXIT_SUCCESS)
// 	// 	ft_env(data);
// 	// else if (ft_findstr(tmp[0], "echo", 4) == EXIT_SUCCESS)
// 	// 	ft_echo(tmp);
// 	// else if (ft_findstr(av[1], "export", 6) == EXIT_SUCCESS)
// 	if (ft_findstr(av[1], "export", 6) == EXIT_SUCCESS)
// 		ft_export(av, env);


// }

// void	ft_initdata(t_data *data, char **env)
// {
// 	// data->dict = ft_getenv(env);
// 	// data->env_start = env;

// }

// /*expand for export*/
// int	main(int ac, char **av, char **env)
// {
// 	t_data data;
// 	t_env main;
// 	(void)ac;
// 	(void)av;
// 	char	*tmp;
// 	// ft_initdata(&data, env); //system
// 	int	i;

// 	i = 0;
// 	main.dict = ft_getenv(env);
// 	printf("%s\n", main.dict->tmp_dict->key);
// 	exit(0);
// 	// ft_buildin(av, env);
// 	printf("ft_buildin\n");
// 	// exit(0);
// 	// ft_buildin(av, &data, envp);
// 	// while (1)
// 	// {
// 	// 	printf("entry\n");
// 	// 	// tmp = readline(BLU"nkietwee % "RESET);
// 	// 	// if (!tmp)
// 	// 	// 	return (0);
// 	// 	// add_history(tmp);
// 	// 	// if (ft_strlen(tmp) > 0)
// 	// 	// ft_buildin(tmp, &data, env);
// 	// 	ft_buildin(av, &data, env);
// 	// 	// free(tmp);
// 	// }


// }