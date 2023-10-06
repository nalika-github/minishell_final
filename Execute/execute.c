/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:26:45 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 06:32:19 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*close fd after dup */
void ft_dup2(t_list *tb_lst, int *fd_tmp_read, int nbr_cmd)
{
	t_table *table;
	t_data *exec_data;

	table = (t_table *)(tb_lst->data);
	exec_data = (t_data *)(&(table->exec_data));
	// dprintf(2, "i_dup2 : %d\n", i);
	// dprintf(2, "nbr_cmd_dup2 : %d\n", nbr_cmd);

	if (exec_data->i == 0 && nbr_cmd == 1) // for 1 cmd
	{
		// dprintf(2, "fd_in_dup2 : %d\n" , exec_data->fd_in);
		// dprintf(2, "fd_here_dup2 : %d\n" , table->fd_heredoc );
		// dprintf(2, "fd_out_dup2 : %d\n", exec_data->fd_out);
		dup2(exec_data->fd_in, STDIN_FILENO);
		dup2(exec_data->fd_out, STDOUT_FILENO);
		// dprintf(exec_data->fd_out, "finish_dup\n");
		if (exec_data->fd_in != STDIN_FILENO)
			close(exec_data->fd_in);
		if (exec_data->fd_out != STDOUT_FILENO)
			close(exec_data->fd_out);
	}
	else if (exec_data->i != nbr_cmd - 1 ) // start with  > 1 cmd
	{
		dprintf(2, "dup 1 cmd\n");
		dup2(exec_data->fd_in, STDIN_FILENO);
		dup2(table->fd_pipe[1], STDOUT_FILENO);
	}
	else if (exec_data->i == nbr_cmd - 1) // end
	{
		dprintf(2, "last cmd\n");
		// printf("fd_out : %d\n", exec_data->fd_out);
		exec_data->fd_out = STDOUT_FILENO; // for test
		dup2(*fd_tmp_read, STDIN_FILENO);
		dup2(exec_data->fd_out, STDOUT_FILENO);
		if (exec_data->fd_out != STDOUT_FILENO)
			close(exec_data->fd_out);
	}
	else // btw
	{
		dprintf(2, "btw cmd\n");
		dup2(*fd_tmp_read, STDIN_FILENO);
		dup2(table->fd_pipe[1], STDOUT_FILENO);
	}
}

// void ft_initdata_exec(t_list *tb_lst)
void ft_initdata_exec(t_list *tb_lst, char **env)
{
	t_table *table;
	int i_cnt = 0;
	table = (t_table *)(tb_lst->data);
	while (tb_lst)
	{
		table = (t_table *)(tb_lst->data);
		table->exec_data.i = i_cnt;
		// dprintf(2, "__i : %d\n", table->exec_data.i);
		table->exec_data.pid = 0;
		table->exec_data.fd_in = 0;
		table->exec_data.fd_out = 0;
		// table->exec_data.fd_pipe[0] = 0;
		// table->exec_data.fd_pipe[1] = 0;
		table->exec_data.nbr_infile = ft_cnt_infile(tb_lst);
		table->exec_data.nbr_out_append = 0;
		table->exec_data.nbr_heredoc = ft_cnt_heredoc(tb_lst);
		// table->exec_data.fd_heredoc = 0;
		// table->
		i_cnt++;
		tb_lst = tb_lst->next;
	}
}

void ft_waitpid(t_minishell *ms, t_list *tb_lst_cpy)
{
	t_table *table_cpy;

	while (tb_lst_cpy)
	{
		table_cpy = (t_table *)(tb_lst_cpy->data);
		waitpid(ms->pid[table_cpy->exec_data.i], NULL, 0);
		tb_lst_cpy = tb_lst_cpy->next;
	}
}

int ft_check_builtin(char **cmd)
{
	int i;

	i = 0;
	// dprintf(2, "ft_check_builtin\n");
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (BUI_CHILD);
	else if (ft_strcmp(cmd[0], "env") == 0)
		return (BUI_CHILD);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		return (BUI_CHILD);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		return (BUI_PARENT);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (BUI_PARENT);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		return (BUI_PARENT);
	else if (ft_strcmp(cmd[0], "export") == 0)
	{
		if (cmd[1] == NULL)
			return (BUI_CHILD);
		return (BUI_PARENT);
	}
	return (CMD_);
}
// void ft_execute(t_list *tb_lst, t_dict *dict, int nbr_cmd)
// void ft_execute(t_list *tb_lst, char **env, int nbr_cmd)
void ft_execute(t_minishell *ms, t_list *tb_lst)
{
	int fd_read;
	t_table *table;
	t_data *data_exec;
	t_list *tb_lst_cpy = NULL;


	fd_read = 0;
	tb_lst_cpy = tb_lst;
	ms->pid = malloc(sizeof(pid_t) * ms->nbr_cmd_all);
	while (tb_lst)
	{
		// dprintf(2, "tb_lst_1\n");
		table = (t_table *)(tb_lst->data);
		data_exec = (t_data *)(&(table->exec_data));

		if (ms->nbr_cmd_all > 1)
		{
			if (pipe(table->fd_pipe) == -1)
				ft_prterr(CANNT_PIPE, "Pipe");
		}
		// dprintf(2, "i_ft_execute : %d\n", data_exec->i);
		table->exec_status = ft_check_builtin(table->cmd);
		ms->pid[data_exec->i] = fork();
		if (ms->pid[data_exec->i] == -1)
			ft_prterr(CANNT_FORK, "Fork");
		if (ms->pid[data_exec->i] == 0)
			branch_child(ms, tb_lst, &fd_read);
			// ft_child(tb_lst, ms->nbr_cmd_all, ms->env, &fd_tmp_read);
		if (ms->pid[data_exec->i] > 0)
			branch_parent(ms, tb_lst, &fd_read);
			// ft_parent(tb_lst, &fd_read, ms->nbr_cmd_all, ms->env);
		// if (data_exec->pid == 0 && ft_check_buildin(table->cmd) == EXIT_FAILURE)
		// 	ft_child(tb_lst, nbr_cmd, dict, &fd_tmp_read);
		// if (data_exec->pid > 0)
		// 	ft_parent(tb_lst, &fd_tmp_read, nbr_cmd, dict);
		tb_lst = tb_lst->next;
	}
	// close(data_exec->fd_out);
	// close(data_exec->fd_in);
	ft_waitpid(ms, tb_lst_cpy);
	free(ms->pid);
}
