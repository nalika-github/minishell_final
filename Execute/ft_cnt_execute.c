/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:33:47 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 01:38:31 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	ft_cnt_heredoc(t_list *tb_list)
int	ft_cnt_heredoc(t_list *tb_list)
{
	int	i;
	t_table *table;
	t_list *rdr_list;
	t_rdr	*rdr;

	i = 0;
	// printf("ft_cnt_heredoc\n");
	while (tb_list)
	{
		table = (t_table *)(tb_list->data);
		rdr_list = table->rdr;
		while (rdr_list)
		{
			rdr = (t_rdr *)(rdr_list->data);
			if (rdr->type == HEREDOC)
			{
				// printf("heredoc : %s\n", rdr->file);
				i++;
			}
			rdr_list = rdr_list->next;
		}
		tb_list = tb_list->next;
	}
	return (i);
}

int	ft_cntcmd(t_list *table_list)
{
	int	i;
	t_table *table;

	i = 0;
	while (table_list)
	{
		table = (t_table *)(table_list->data);
		if (table->cmd[0] != NULL)
			i++;
		table_list = table_list->next;
	}
	return (i);
}

int	ft_cnt_infile(t_list *table_list)
{
	int	i;
	t_table *table;
	t_rdr	*rdr;
	t_list	*rdr_lst;

	i = 0;
	table = (t_table *)(table_list->data);
	rdr_lst = (t_list *)(table->rdr);
	while (rdr_lst)
	{
		rdr = (t_rdr *)(rdr_lst->data);
		// ft_prt_type(rdr->type);
		if (rdr->type == INFILE)
			i++;
		rdr_lst = rdr_lst->next;
	}
	// dprintf(2, "Finish_cnt_infile\n");
	return (i);
}

int	ft_cnt_outfile(t_list *table_list)
{
	int	i;
	t_table *table;
	t_rdr	*rdr;
	t_list	*rdr_lst;

	i = 0;
	table = (t_table *)(table_list->data);
	rdr_lst = (t_list *)(table->rdr);
	while (rdr_lst)
	{
		rdr = (t_rdr *)(rdr_lst->data);
		// ft_prt_type(rdr->type);
		if (rdr->type == OUTFILE || rdr->type == APPEND)
			i++;
		rdr_lst = rdr_lst->next;
	}
	// dprintf(2, "Finish_cnt_infile\n");
	return (i);
}