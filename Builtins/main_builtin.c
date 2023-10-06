/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:58:16 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 01:49:16 by nkietwee         ###   ########.fr       */
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

void	ft_child_builtin(t_minishell *ms, t_list *tb_lst)
{
	t_table	*table;
	// t_data	*exec_data;

	table = (t_table *)(tb_lst->data);
	// exec_data = (t_data *)(&(table->exec_data));
	ft_getfd(ms, tb_lst);
	if (table->fd_in == -1)
		return ;
	ft_dup2(ms, tb_lst);
	ft_close_pipe(ms, tb_lst);
	if (table->exec_status == 1)
	{
		if ((ft_strcmp(table->cmd[0], "export") == 0) && !table->cmd[1])
			ft_export(table->cmd,  ms->dict);
		if (ft_strcmp(table->cmd[0], "echo") == 0)
			ft_echo(table->cmd , table->fd_out);
		if (ft_strcmp(table->cmd[0], "pwd") == 0)
			ft_pwd();
		if (ft_strcmp(table->cmd[0], "env") == 0)
			ft_env(ms->dict);
	}
}

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