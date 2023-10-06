/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:26:45 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 02:45:15 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_check_buildin(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "export") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "unset") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "env") == 0)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/*close fd after dup */
// void ft_dup2(int i, t_list *tb_lst, int *fd_tmp_read, int nbr_cmd)
// {
// 	t_table *table;
// 	t_data *exec_data;

// 	table = (t_table *)(tb_lst->data);
// 	exec_data = (t_data *)(&(table->exec_data));
// 	// dprintf(2, "i : %d\n", i);
// 	// dprintf(2, "nbr_cmd : %d\n", nbr_cmd);

// 	if (i == 0 && nbr_cmd == 1) // for 1 cmd
// 	{
// 		// dprintf(2, "fd_in_dup2 : %d\n" , exec_data->fd_in);
// 		// dprintf(2, "fd_here_dup2 : %d\n" , table->fd_heredoc );
// 		// dprintf(2, "fd_out_dup2 : %d\n", exec_data->fd_out);
// 		dup2(exec_data->fd_in, STDIN_FILENO);
// 		dup2(exec_data->fd_out, STDOUT_FILENO);
// 		// dprintf(exec_data->fd_out, "finish_dup\n");
// 		if (exec_data->fd_in != STDIN_FILENO )
// 			close(exec_data->fd_in);
// 		if (exec_data->fd_out != STDOUT_FILENO)
// 			close(exec_data->fd_out);

// 	}
// 	else if (i == 0 && nbr_cmd > 1) // start with  > 1 cmd
// 	{
// 		// dprintf(2, "dup 1 cmd\n");
// 		dup2(exec_data->fd_in, STDIN_FILENO);
// 		dup2(exec_data->fd_pipe[1], STDOUT_FILENO);
// 	}
// 	else if (i == nbr_cmd - 1) // end
// 	{
// 		// dprintf(2 , "last cmd\n");
// 		// printf("fd_out : %d\n", exec_data->fd_out);
// 		exec_data->fd_out = STDOUT_FILENO; // for test
// 		dup2(*fd_tmp_read, STDIN_FILENO);
// 		dup2(exec_data->fd_out, STDOUT_FILENO);
// 	}
// 	else //btw
// 	{
// 		// printf("btw cmd\n");
// 		dup2(*fd_tmp_read, STDIN_FILENO);
// 		dup2(exec_data->fd_pipe[1], STDOUT_FILENO);
// 	}
// }

// void ft_initdata_exec(t_list *tb_lst)
void ft_initdata_exec(t_list *tb_lst, char **env)
{
	t_table *table;
	int i_cnt = 0;
	table = (t_table *)(tb_lst->data);
	while (tb_lst)
	{
		table = (t_table *)(tb_lst->data);
		table->i = i_cnt;
		// table->exec_data.pid = 0;
		table->fd_in = 0;
		table->fd_out = 0;
		// table->exec_data.fd_pipe[0] = 0;
		// table->exec_data.fd_pipe[1] = 0;
		table->nbr_infile = ft_cnt_infile(tb_lst);
		table->nbr_outfile = ft_cnt_outfile(tb_lst);
		table->nbr_heredoc = ft_cnt_heredoc(tb_lst);
		// table->exec_data.fd_heredoc = 0;
		// table->
		i_cnt++;
		tb_lst = tb_lst->next;
	}
}

// void ft_waitpid(t_list *tb_lst_cpy)
// {
// 	t_table	*table_cpy;
// 	t_data	data_exec_cpy;

// 	while (tb_lst_cpy)
// 	{
// 		table_cpy = (t_table *)(tb_lst_cpy->data);
// 		data_exec_cpy = (table_cpy->exec_data) ;
// 		waitpid(data_exec_cpy.pid, NULL, 0);
// 		tb_lst_cpy = tb_lst_cpy->next;
// 	}
// }

void ft_waitpid(t_minishell *ms, t_list *tb_lst_cpy)
{
	t_table *table_cpy;

	while (tb_lst_cpy)
	{
		table_cpy = (t_table *)(tb_lst_cpy->data);
		waitpid(ms->pid[table_cpy->i], NULL, 0);
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

void ft_parent_builtin(t_minishell *ms, t_list *tb_lst)
{
	t_table *table;
	// t_dict	*tmp_env;

	table = (t_table *)(tb_lst->data);
	ft_getfd(ms, tb_lst);
	table->fd_tmp = dup(table->fd_pipe[0]);
	ft_close_pipe(ms, tb_lst);
	if (table->exec_status == 2)
	{
		if (ft_strcmp(table->cmd[0], "cd") == 0)
			ft_cd(table->cmd, ms->dict);
		if ((ft_strcmp(table->cmd[0], "export") == 0) && table->cmd[1])
			ft_export(table->cmd, ms->dict);
		if (ft_strcmp(table->cmd[0], "unset") == 0)
			ft_unset(table->cmd, &ms->dict);
		if (ft_strcmp(table->cmd[0], "exit") == 0)
			ft_exit(table->cmd, ms->dict);
	}
}

void ft_parent_do_nothing(t_minishell *ms, t_list *tb_lst)
{
	t_table *table;
	// t_data exec_data;
	// dprintf(2, "Hello from parent\n");
	table = (t_table *)(tb_lst->data);
	// exec_data = (t_data)(table->exec_data);
	// dprintf(2, "ft_parent_do_nothing\n");
	table->fd_tmp = dup(table->fd_pipe[0]); // another process can read from previos process
	dprintf(2, "fd_tmp[%d] : %d\n", table->i, table->fd_tmp);
	ft_close_pipe(ms, tb_lst);
}

void branch_parent(t_minishell *ms, t_list *tb_lst)
{
	// dprintf(2, "branch_parent\n");
	// exit(0);
	t_table *table;

	table = (t_table *)(tb_lst->data);
	// dprintf(2, "---parent[%d] table->exec_status: %d\n", table->i, table->exec_status);

	if (table->exec_status == BUI_PARENT)
		ft_parent_builtin(ms, tb_lst);
	else // table->exec_status == 1
		ft_parent_do_nothing(ms, tb_lst);
	// ft_parent_do_nothing(ms, tb_lst);
	dprintf(2, "fd_tmp_bramch[%d] : %d\n", table->i, table->fd_tmp);
}

int ft_checkpath(t_dict *dict)
{
	int found;

	found = 0;
	while (dict)
	{
		if (ft_strcmp(dict->tmp_dict->key, "PATH") == 0)
			found = 1;
		dict = dict->next;
	}
	return (found);
}

void branch_child(t_minishell *ms, t_list *tb_lst)
{
	// dprintf(2, "branch_child\n");
	// exit(0);
	t_table *table;

	table = (t_table *)(tb_lst->data);
	// dprintf(2, "branch_child\n");
	// exit(0);
	/*check unset PATH*/
	if (ft_checkpath(ms->dict) == 0)
		ft_prterrexec(table->cmd[0], 127, ERR_PATH);
	if (table->exec_status == CMD_)
		ft_child_execve(ms, tb_lst);
	else if (table->exec_status == BUI_CHILD)
		ft_child_builtin(ms, tb_lst);
}

// void ft_execute(t_list *tb_lst, t_dict *dict, int nbr_cmd)
void ft_execute(t_minishell *ms, t_list *tb_lst, int nbr_cmd)
{
	t_table *table;
	t_list *tb_lst_cpy = NULL;

	table = (t_table *)(tb_lst->data);
	ms->pid = malloc(sizeof(pid_t) * ms->nbr_cmd_all); // don't forget incase no cmd
	// dprintf(2, "cmd : %d\n", ms->nbr_cmd_all);
	// dprintf(2, "i : %d\n", table->i);
	// exit(0);
	// dprintf(2, "ft_execute\n");
	// exit(0);
	tb_lst_cpy = tb_lst;
	while (tb_lst)
	{
		table = (t_table *)(tb_lst->data);
		if (ms->nbr_cmd_all > 1)
		{
			if (pipe(table->fd_pipe) == -1)
				ft_prterr(CANNT_PIPE, "Pipe");
		}
		table->exec_status = ft_check_builtin(table->cmd);
		ms->pid[table->i] = fork();
		if (ms->pid[table->i] == 0)
			branch_child(ms, tb_lst);
		else
			branch_parent(ms, tb_lst);
		// close(table->fd_out);
		// close(table->fd_in);
		tb_lst = tb_lst->next;
	}
	ft_waitpid(ms, tb_lst_cpy);
	free(ms->pid);
}

// // void ft_execute(t_list *tb_lst, t_dict *dict, int nbr_cmd)
// void ft_execute(t_list *tb_lst, char **env, int nbr_cmd)
// {
// 	int		fd_tmp_read;
// 	t_table	*table;
// 	t_data	*data_exec;
// 	t_list	*tb_lst_cpy = NULL;

// 	fd_tmp_read = 0;
// 	// (void)dict;
// 	tb_lst_cpy = tb_lst;
// 	while (tb_lst)
// 	{
// 		// dprintf(2, "tb_lst_1\n");
// 		table = (t_table *)(tb_lst->data);
// 		data_exec = (t_data *)(&(table->exec_data));
// 		if (nbr_cmd > 1)
// 		{
// 			if (pipe(data_exec->fd_pipe) == -1)
// 				ft_prterr(CANNT_PIPE, "Pipe");
// 		}
// 		if (ft_check_buildin(table->cmd) == EXIT_FAILURE)
// 			data_exec->pid = fork();
// 		if (data_exec->pid == -1)
// 			ft_prterr(CANNT_FORK, "Fork");
// 		if (data_exec->pid == 0 && ft_check_buildin(table->cmd) == EXIT_FAILURE)
// 			ft_child(tb_lst, nbr_cmd, env, &fd_tmp_read);
// 		if (data_exec->pid > 0)
// 			ft_parent(tb_lst, &fd_tmp_read, nbr_cmd, env);
// 		// if (data_exec->pid == 0 && ft_check_buildin(table->cmd) == EXIT_FAILURE)
// 		// 	ft_child(tb_lst, nbr_cmd, dict, &fd_tmp_read);
// 		// if (data_exec->pid > 0)
// 		// 	ft_parent(tb_lst, &fd_tmp_read, nbr_cmd, dict);
// 		tb_lst = tb_lst->next;
// 	}
// 	// close(data_exec->fd_out);
// 	// close(data_exec->fd_in);
// 	ft_waitpid(tb_lst_cpy);
// }
