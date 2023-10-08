/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:46:22 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/08 18:23:17 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_accessfile(char *file, int type)
{
	int errno;

	errno = 127; // check
	// ft_prt_type(type);
	if (type == HEREDOC || type == OUTFILE || type == APPEND)
		return (EXIT_SUCCESS);
	if (access(file, F_OK) == 0)
	{
		if (access(file, R_OK | F_OK) == -1)
		{
			ft_prterrexec(file, errno, PER_FILE);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		ft_prterrexec(file, errno, NO_FILE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int ft_getfd_in(t_list *tb_lst)
{
	int fd_in;
	int i;
	t_table *table;
	t_rdr *rdr;
	t_list *rdr_lst;

	i = 0;
	table = (t_table *)(tb_lst->data);
	rdr_lst = (t_list *)(table->rdr);
	while (rdr_lst)
	{
		rdr = (t_rdr *)(rdr_lst->data);
		if (ft_accessfile(rdr->file, rdr->type) == EXIT_FAILURE)
			return (-1);
		if (rdr->type == INFILE)
			fd_in = open(rdr->file, O_RDONLY);
		rdr_lst = rdr_lst->next;
	}
	return (fd_in);
}
int ft_getfd_heredoc(t_list *tb_lst)
{
	int fd_in;
	t_table *table;
	t_rdr *rdr;
	t_list *rdr_lst;

	table = (t_table *)(tb_lst->data);
	rdr_lst = (t_list *)(table->rdr);
	while (rdr_lst)
	{
		rdr = (t_rdr *)(rdr_lst->data);
		if (rdr->type == HEREDOC)
			fd_in = table->exec_data.fd_heredoc ;
		rdr_lst = rdr_lst->next;
	}
	return (fd_in);
}

int ft_getfd_out(t_list *tb_lst)
{
	int fd_out;
	t_table *table;
	t_rdr *rdr_lst;

	while (tb_lst)
	{
		table = (t_table *)(tb_lst->data);
		while (table->rdr)
		{
			rdr_lst = (t_rdr *)(table->rdr->data);
			// dprintf(2, "getfd_out_1\n");
			if (rdr_lst->type == OUTFILE)
			{
				// dprintf(2, "file : %s\n", rdr_lst->file);
				fd_out = open(rdr_lst->file, O_RDWR | O_CREAT | O_TRUNC, 0644);
				// dprintf(2, "fd_out[] : %d\n", fd_out);
			}
			else if (rdr_lst->type == APPEND)
				fd_out = open(rdr_lst->file, O_RDWR | O_CREAT | O_APPEND, 0644);
			// if (ft_accessfile(rdr_lst->file, rdr_lst->type) == EXIT_FAILURE)
			// 	return(-1);
			table->rdr = table->rdr->next;
		}
		tb_lst = tb_lst->next;
	}
	// dprintf(2, "fd_out[] : %d\n", fd_out);
	return (fd_out);
}

/* don't fotget check name of file */
void ft_getfd(t_list *tb_lst)
{
	int nbr_infile;
	int nbr_outfile;
	t_table *table;
	t_data *exec_data;

	table = (t_table *)(tb_lst->data);
	exec_data = &table->exec_data;
	// dprintf(2, "nbr_heredoc_gerfd : %d\n", exec_data->nbr_heredoc);
	exec_data->nbr_infile = ft_cnt_infile(tb_lst);
	if (exec_data->nbr_infile == 0 && exec_data->nbr_heredoc == 0) // no infile
		exec_data->fd_in = STDIN_FILENO;
	else if (exec_data->nbr_infile == 0 && exec_data->nbr_heredoc != 0)
		exec_data->fd_in = ft_getfd_heredoc(tb_lst);
	else // It have both
		exec_data->fd_in = ft_getfd_in(tb_lst);

	// dprintf(2,  "fd_in_getfd : %d\n" , exec_data->fd_in);

	exec_data->nbr_out_append = ft_cnt_outfile(tb_lst);
	if (exec_data->nbr_out_append == 0) // no outfile
		exec_data->fd_out = STDOUT_FILENO;
	else
		exec_data->fd_out = ft_getfd_out(tb_lst);
	// dprintf(2, "nbr_oufile : %d\n", exec_data->nbr_out_append);
	// dprintf(2 , "fd_in_getfd__ :  %d\n", exec_data->fd_in);
	// dprintf(2 , "fd_out_getfd__ :  %d\n", exec_data->fd_out);
}