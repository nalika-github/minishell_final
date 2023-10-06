/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:10:26 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 05:58:51 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_execvecmd(char **cmd, char **path, char **env)
{
	int		i;
	char	*path_exec;

	i = 0;
	if (!cmd)
		return ;
	while (path[i])
	{
		path_exec = ft_strjoinextra(path[i], cmd[0], NONE);
		// free(cmd[0]);
		// dprintf(2, "path_exec : %s\n", path_exec);
		if (access(path_exec, F_OK) == EXIT_SUCCESS)
		{
			cmd[0] = path_exec;
			if (execve(path_exec, cmd, env) == -1)
			{
				ft_putstr_fd("Can't execve\n" , STDOUT_FILENO);
				// exit(0);
			}
		}
		free(path_exec);
		i++;
	}
	// dprintf(2, "path_exec____ \n");
	if (path[i] == NULL)
		ft_prterrexec(cmd[0], 1, ERR_CMD);
}

void	ft_execvepath(char **path, char **tmp_env)
{
	// dprintf(2, "Entry : execvepath\n");
	if (access(path[0], F_OK | X_OK) == -1)
	{
		ft_prterrexec(path[0], 1, ERR_PATH);
		// ft_dbfree((void **)path); // ??
	}
	else
		execve(path[0], path, tmp_env);
}

void	ft_prtcmd(t_list *tb_lst, int i)
{
	t_table *table;

	table = (t_table *)(tb_lst->data);
	printf("cmd[%d] : %s\n", i, table->cmd[0]);

}



void ft_close_pipe(t_minishell *ms, t_list *tb_lst)
{
	t_table *table;

	table = (t_table *)(tb_lst->data);
	if (ms->nbr_cmd_all > 1)
	{
		close(table->fd_pipe[0]);
		close(table->fd_pipe[1]);
	}
}



/* void	ft_child(t_list *tb_lst, int nbr_cmd, t_dict *dict, int *fd_tmp_read)
{
	char **cmd;
	t_table	*table;
	t_data	*exec_data;
	char	**path;

	// check unset path
	table = (t_table *)(tb_lst->data);
	exec_data = (t_data *)(&(table->exec_data));
	// int i = -1;
	// while (table->tmp_env[++i])
	// 	dprintf(2, "env[%d] : %s\n", i, table->tmp_env[i]);
	// printf("findpath1\n");
	// exit(0);
	path = ft_findpath(table->tmp_env); // fixed from env to t_dict *dict
	// exit(0);
	// dprintf(2, "Hello from child\n");
	// ft_prtcmd(tb_lst, table->i);
	// dprintf(2, "fd_here_child_1 : %d\n", table->fd_heredoc);
	ft_getfd(tb_lst);
	// dprintf(2, "fd_here_child_2 : %d\n", table->fd_heredoc);
	if (exec_data->fd_in == -1)
		return ;
	ft_dup2(table->i, tb_lst, fd_tmp_read, nbr_cmd);
	// dprintf(2, "fd_inchild_2 : %d\n", exec_data->fd_in);
	// dprintf(2, "fd_outchild_2 : %d\n", exec_data->fd_out);
	// ft_buildin_child(table->cmd, env, exec_data->fd_out);
	// if (table->fd_heredoc > 2)
	// 	close(table->fd_heredoc);
	if (nbr_cmd > 1)
	{
		close(exec_data->fd_pipe[0]);
		close(exec_data->fd_pipe[1]);
	}
	if (ft_findchar(table->cmd[0], '/') == EXIT_SUCCESS) // cmd or av4
		ft_execvepath(table->cmd, table->tmp_env);
	else
		ft_execvecmd(table->cmd, path, table->tmp_env);
} */
