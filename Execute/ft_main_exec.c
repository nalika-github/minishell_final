/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:14:59 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 04:54:36 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_buildin_onecmd(t_minishell *ms)
{
	t_table	*table;
	t_dict	*tmp_env;

	table = (t_table *)(ms->tb_lst->data);
	if (ft_check_builtin(table->cmd) == EXIT_SUCCESS)
		ft_getfd(ms->tb_lst);
	if (ms->nbr_cmd_all)
	{
		if (ft_strcmp(table->cmd[0], "echo") == 0)
			ft_echo(table->cmd , table->exec_data.fd_out);
		if (ft_strcmp(table->cmd[0], "cd") == 0)
			ft_cd(table->cmd, ms->dict);
		if (ft_strcmp(table->cmd[0], "pwd") == 0)
			ft_pwd();
		if (ft_strcmp(table->cmd[0], "export") == 0)
			ft_export(table->cmd, ms->dict);
		if (ft_strcmp(table->cmd[0], "env") == 0)
			ft_env(ms->dict);
		if (ft_strcmp(table->cmd[0], "unset") == 0)
			ft_unset(table->cmd, &ms->dict);
		if (ft_strcmp(table->cmd[0], "exit") == 0)
			ft_exit(table->cmd, ms->dict);
	}
}
void	ft_mainexec(t_minishell *ms)
{
	// if (ft_checkfile(ms->tb_lst) == EXIT_FAILURE)
	// 	return ;
	// ft_countexec(ms);
	t_table	*table;

	table = (ms->tb_lst->data);
	table->nbr_heredoc = ft_cnt_heredoc(ms->tb_lst);
	// dprintf(2, "nbr_here : %d\n" , table->nbr_heredoc);
	if (table->nbr_heredoc > 0)
		table->fd_heredoc = ft_heredoc(ms->tb_lst , table->nbr_heredoc);
	// dprintf(2, "fd_here : %d\n", table->fd_heredoc);
	// ft_heredoc(ms->tb_lst , 3);
	// exit(0);
	ms->nbr_cmd_all = ft_cntcmd(ms->tb_lst);
	// if (ms->nbr_cmd == 0 && table->nbr_heredoc > 0)
	// 	return;
	ft_initdata_exec(ms->tb_lst , ms->env);
	// ft_buildin_onecmd(ms);
	ft_execute(ms, ms->tb_lst);
	// ft_execute(ms->tb_lst, ms->dict, ms->nbr_cmd);

}