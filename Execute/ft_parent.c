/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:58:25 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 06:17:37 by nkietwee         ###   ########.fr       */
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
	*fd_read = dup(table->fd_pipe[0]); // another process can read from previos process
	dprintf(2, "fd_tmp[%d] : %d\n", table->exec_data.i, *fd_read);
	ft_close_pipe(ms, tb_lst);
}

void branch_parent(t_minishell *ms, t_list *tb_lst, int *fd_read)
{
	// dprintf(2, "branch_parent\n");
	// exit(0);
	t_table *table;

	table = (t_table *)(tb_lst->data);

	// if (table->exec_status == BUI_PARENT)
	// 	ft_parent_builtin(ms, tb_lst);
	// else // table->exec_status == 1
	// 	ft_parent_do_nothing(ms, tb_lst, fd_read);
	ft_parent_do_nothing(ms, tb_lst, fd_read);
}