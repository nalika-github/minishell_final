/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:58:25 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/08 18:58:40 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_parent_do_nothing(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	t_table *table;
	t_data *exec_data;
	// dprintf(2, "Hello from parent\n");
	table = (t_table *)(tb_lst->data);
	exec_data = (t_data *)( &(table->exec_data));
	// dprintf(2, "ft_parent_do_nothing\n");
	if (ms->nbr_cmd_all > 0)
		*fd_read = dup(table->fd_pipe[0]); // another process can read from previos process
	// dprintf(2, "fd_tmp[%d] : %d\n", table->exec_data.i, *fd_read);
	ft_close_pipe(ms, tb_lst);
}

void	ft_parent_builtin(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	t_table	*table;

	table = (t_table *)(tb_lst->data);
	ft_getfd(tb_lst);
	*fd_read = dup(table->fd_pipe[0]);
	ft_close_pipe(ms, tb_lst);
	dprintf(2, "parent_builtin\n");
	if (table->exec_status == BUI_PARENT)
	{
		if (ft_strcmp(table->cmd[0], "cd") == 0)
			ft_cd(table->cmd, ms->dict);
		if ((ft_strcmp(table->cmd[0], "export") == 0) && table->cmd[1])
			ft_export(table->cmd,  &ms->dict);
		if (ft_strcmp(table->cmd[0], "unset") == 0)
			ft_unset(table->cmd, &ms->dict);
		if (ft_strcmp(table->cmd[0], "exit") == 0)
			ft_exit(table->cmd, ms->dict);
	}
}

t_dict *branch_parent(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	t_table *table;

	table = (t_table *)(tb_lst->data);
	// dprintf(2, "branch_parent\n");
	if (ft_checkpath(ms->dict) == 0)
		ft_prterrexec(table->cmd[0], 127, ERR_PATH);
	if (table->exec_status == BUI_PARENT)
		ft_parent_builtin(ms, tb_lst, fd_read);
	else // table->exec_status == 1
		ft_parent_do_nothing(ms, tb_lst, fd_read);
	// exit(0);
	return (ms->dict);
}