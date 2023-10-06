/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:48:56 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 06:21:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_child_execve(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	t_table *table;
	t_data *exec_data;
	char **path;

	table = (t_table *)(tb_lst->data);
	exec_data = (t_data *)(&(table->exec_data));
	path = ft_findpath(ms->env); // fixed from env to t_dict *dict
	// dprintf(2, "ft_child_execve\n");
	// exit(0);
	ft_getfd(tb_lst);
	if (exec_data->fd_in == -1)
		return;
	ft_dup2(tb_lst, fd_read, ms->nbr_cmd_all);
	ft_close_pipe(ms, tb_lst);
	if (ft_findchar(table->cmd[0], '/') == EXIT_SUCCESS) // cmd or av4
		ft_execvepath(table->cmd, ms->env);
	else
	{
		dprintf(2, "ft_child_exve %d\n\n", table->exec_data.i);
		ft_execvecmd(table->cmd, path, ms->env);
	}
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
void	ft_child_builtin(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	t_table	*table;
	t_data	*exec_data;
	// t_data	*exec_data;

	table = (t_table *)(tb_lst->data);
	exec_data = (t_data *)(&(table->exec_data));
	ft_getfd(tb_lst);
	if (exec_data->fd_in == -1)
		return ;
	ft_dup2(tb_lst, fd_read, ms->nbr_cmd_all);
	ft_close_pipe(ms, tb_lst);
	if (table->exec_status == 1)
	{
		if ((ft_strcmp(table->cmd[0], "export") == 0) && table->cmd[1] == NULL)
			ft_export(table->cmd,  ms->dict);
		if (ft_strcmp(table->cmd[0], "echo") == 0)
			ft_echo(table->cmd , exec_data->fd_out);
		if (ft_strcmp(table->cmd[0], "pwd") == 0)
			ft_pwd();
		if (ft_strcmp(table->cmd[0], "env") == 0)
			ft_env(ms->dict);
	}
}

void	branch_child(t_minishell  *ms, t_list *tb_lst, int *fd_read)
{
	t_table	*table;
	// t_data	*exec_data;

	// // check unset path

	table = (t_table *)(tb_lst->data);
	// exec_data = (t_data *)(&(table->exec_data));
	if (ft_checkpath(ms->dict) == 0)
		ft_prterrexec(table->cmd[0], 127, ERR_PATH);
	if (table->exec_status == CMD_)
		ft_child_execve(ms ,tb_lst, fd_read);
	else if (table->exec_status == BUI_CHILD)
		ft_child_builtin(ms, tb_lst, fd_read);



}