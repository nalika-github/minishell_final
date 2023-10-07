/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:14:59 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 20:43:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_mainexec(t_minishell *ms)
{
	// if (ft_checkfile(ms->tb_lst) == EXIT_FAILURE)
	// 	return ;
	// ft_countexec(ms);
	t_table	*table;

	table = (ms->tb_lst->data);
	table->nbr_heredoc = ft_cnt_heredoc(ms->tb_lst);
	// if (table->nbr_heredoc > 0)
	// 	ft_main_heredoc(ms->tb_lst);
		// ft_heredoc(ms->tb_lst);
	if (ms->nbr_cmd_all == 0 && table->nbr_heredoc > 0)
		return;
	ms->nbr_cmd_all = ft_cntcmd(ms->tb_lst);
	ft_initdata_exec(ms->tb_lst , ms->env);
	ft_execute(ms, ms->tb_lst);
}