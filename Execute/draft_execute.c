/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:26:45 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/01 02:37:23 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* left loop in case it many pipe (It have outfile?)*/
void	ft_dup2(int i, int j, t_data *data)
{
	// printf("ft_dup2\n");
	if (i == 0 && data->nbr_cmd == 1) // start with 1 cmd
	{
		// printf("dup only 1 cmd\n");
		// printf("fd_in : %d\n" , data->fd_in);
		dup2(data->fd_in, STDIN_FILENO);
		dup2(data->fd_out, STDOUT_FILENO);
	}
	else if (i == 0 && data->nbr_cmd != 1) // start with  > 1 cmd
	{
		// printf("dup 1 cmd\n");
		dup2(data->fd_in, STDIN_FILENO);
		dup2(data->fd_pipe[1], STDOUT_FILENO);
	}
	else if (i == data->nbr_cmd - 1) // end
	{
		// printf("last cmd\n");
		// printf("fd_out : %d\n", data->fd_out);
		dup2(data->fd_tmp_read, STDIN_FILENO);
		dup2(data->fd_out, STDOUT_FILENO);
	}
	else //btw
	{
		printf("btw cmd\n");
		dup2(data->fd_tmp_read, STDIN_FILENO);
		dup2(data->fd_pipe[1], STDOUT_FILENO);
	}
}

void	ft_execvecmd(char **cmd, char **path, char **tmp_env)
{
	int		i;
	char	*path_exec;

	i = 0;
	if (!cmd)
		return ;
	while (path[i])
	{
		path_exec = ft_strjoinextra(path[i], cmd[0], NONE);
		if (access(path_exec, F_OK) == EXIT_SUCCESS)
		{
			execve(path_exec, cmd, tmp_env);
		}
		free(path_exec);
		i++;
	}
	if (path[i] == NULL)
		ft_prterrexec(cmd[0], 1, ERR_CMD);
}


void	ft_execvepath(char **path, char **tmp_env)
{
	// printf("Entry : execvepath\n");
	if (access(path[0], F_OK | X_OK) == -1)
	{
		ft_prterrexec(path[0], 1, ERR_PATH);
		printf("not access\n");
		// ft_dbfree((void **)path); // ??
	}
	else
	{
		// printf("path\n");
		execve(path[0], path, tmp_env);
	}
}

void	ft_parent(t_data *data)
{
	data->fd_tmp_read = dup(data->fd_pipe[0]); // another process can read from previos process
	// printf("tmp_read : %d\n" , data->fd_tmp_read);
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);

	// export
	// cd
	// unset
	// exit
}

void	ft_child(int i, t_data *data, int j)
{
	char **cmd;

	ft_dup2(i, j, data);
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	cmd = ft_split(data->tmp_av[j], ' ');
	printf("cmd : %s\n", cmd[0]);
	if (ft_findchar(cmd[0], '/') == EXIT_SUCCESS) // cmd or av4
		ft_execvepath(cmd, data->tmp_env);
	else
		ft_execvecmd(cmd, data->path, data->tmp_env);
}

void	ft_execute(t_minishell *ms, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	ms->data.nbr_cmd = ft_cntcmd(ms->tb_lst);
	ms->data.pid = malloc(sizeof(pid_t) * ms->data.nbr_cmd);
	if (!ms->data.pid)
		return ;
	ft_getfd(ms);
	i = 0;
	printf("nbr_cmd : %d\n" ,ms->data.nbr_cmd);
	while(i < ms->data.nbr_cmd)
	{
		if (pipe(ms->data.fd_pipe)== -1)
			ft_prterr(CANNT_PIPE);
		ms->data.pid[i] = fork();
		if (ms->data.pid[i] == -1)
			ft_prterr(CANNT_FORK);
		else if (ms->data.pid[i] == 0)
			ft_child(i, &ms->data, j);
		else
			ft_parent(&ms->data);
		i++;
		j++;
	}
	int k = 0;
	while(k < ms->data.nbr_cmd)
	{
		waitpid(ms->data.pid[k], NULL, 0);
		k++;
	}
}


