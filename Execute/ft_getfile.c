/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:46:22 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 02:43:10 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_accessfile(char *file, int type)
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

int	ft_getfd_in(t_list *tb_lst)
{
	int		fd_in;
	int		i;
	t_table *table;
	t_rdr	*rdr;
	t_list	*rdr_lst;

	i = 0;
	table = (t_table *)(tb_lst->data);
	rdr_lst = (t_list *)(table->rdr);
	while (rdr_lst)
	{
		rdr = (t_rdr *)(rdr_lst->data);
		if (ft_accessfile(rdr->file, rdr->type) == EXIT_FAILURE)
			return(-1);
		if (rdr->type == INFILE)
			fd_in = open(rdr->file, O_RDONLY);
		else if (rdr->type == HEREDOC)
			fd_in = table->fd_heredoc;
		rdr_lst = rdr_lst->next;
	}
	return (fd_in);



	// while (tb_lst)
	// {
	// 	table = (t_table *)(tb_lst->data);
	// 	while (table->rdr)
	// 	{
	// 		// dprintf(2, "ft_getfd_in\n");
	// 		rdr_lst = (t_rdr *)(table->rdr->data);
	// 		if (ft_accessfile(rdr_lst->file, rdr_lst->type) == EXIT_FAILURE)
	// 		{
	// 			// dprintf(2, "exit_fdin\n");
	// 			return(-1);
	// 		}
	// 		if (rdr_lst->type == INFILE)
	// 			fd_in = open(rdr_lst->file, O_RDONLY);
	// 		else if (rdr_lst->type == HEREDOC)
	// 			fd_in = table->fd_heredoc;
	// 		table->rdr = table->rdr->next;
	// 	}
	// 	tb_lst = tb_lst->next;
	// }
	// dprintf(2, "fd_here_getfd_in : %d\n", fd_in);
	// exit(0);
	// return (fd_in);
}

int	ft_getfd_out(t_list *tb_lst)
{
	int		fd_out;
	t_table *table;
	t_rdr	*rdr_lst;

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
				fd_out = open(rdr_lst->file, O_RDWR | O_CREAT | O_TRUNC , 0644);
				// dprintf(2, "fd_out[] : %d\n", fd_out);
			}
			else if (rdr_lst->type == APPEND)
				fd_out = open(rdr_lst->file, O_RDWR | O_CREAT | O_APPEND , 0644);
			// if (ft_accessfile(rdr_lst->file, rdr_lst->type) == EXIT_FAILURE)
			// 	return(-1);
			table->rdr = table->rdr->next;
		}
		tb_lst = tb_lst->next;
	}
	// dprintf(2, "fd_out[] : %d\n", fd_out);
	return (fd_out);
}

// /* /* don't fotget check name of file */
// void	ft_getfd(t_list *tb_lst)
// {
// 	int		nbr_infile;
// 	int		nbr_outfile;
// 	t_table	*table;
// 	t_data	*exec_data;

// 	table = (t_table *)(tb_lst->data);
// 	exec_data =  &table->exec_data;
// 	nbr_infile = ft_cnt_infile(tb_lst);
// 	if (nbr_infile == 0 && table->nbr_heredoc == 0) // no infile
// 		exec_data->fd_in = STDIN_FILENO;
// 	else
// 		exec_data->fd_in = ft_getfd_in(tb_lst);
// 	nbr_outfile = ft_cnt_outfile(tb_lst);
// 	if (nbr_outfile == 0) // no outfile
// 		exec_data->fd_out = STDOUT_FILENO;
// 	else
// 		exec_data->fd_out = ft_getfd_out(tb_lst);
// 	// dprintf(2 , "fd_in_getfd__ :  %d\n", exec_data->fd_in);
// 	// dprintf(2 , "fd_out_getfd__ :  %d\n", exec_data->fd_out);
// } */


/* don't fotget check name of file */
void	ft_getfd(t_minishell *ms, t_list *tb_lst)
{
	(void)ms;
	(void)tb_lst;
	t_table	*table;

	table = (t_table *)(tb_lst->data);
	table->nbr_infile = ft_cnt_infile(tb_lst);
	table->nbr_outfile = ft_cnt_outfile(tb_lst);
	// dprintf(2, "nbr_infile : %d\n", table->nbr_infile);
	// dprintf(2, "nbr_outfile : %d\n", table->nbr_outfile);
	dprintf(2, "fd_tmp : %d\n", table->fd_tmp);
	// exit(0);
	/*get fd_in*/
	if (table->nbr_infile)
	{
		dprintf(2, "ft_getfdin_1\n");
		table->fd_in = ft_getfd_in(tb_lst);
	}
	// else if (table->i > 0 && table->i != ms->nbr_cmd_all)
	else if (table->i != 0)
	{
		dprintf(2, "ft_getfdin_3\n");
		// table->fd_in = table->fd_pipe[0];
		table->fd_in = table->fd_tmp;
	}
	// else if (table->nbr_infile == 0 && table->i == 0)
	// {
	// 	dprintf(2, "ft_getfdin_2\n");
	// 	table->fd_in = STDIN_FILENO;
	// }

	/*get fd_out*/
	if (table->nbr_outfile) // no outfile
	{
		dprintf(2, "ft_getfdout_1\n");
		table->fd_out = ft_getfd_out(tb_lst);
	}
	else if (table->i == ms->nbr_cmd_all - 1 && table->nbr_outfile == 0)
	{
		dprintf(2, "ft_getfdout_3\n");
		table->fd_out = STDOUT_FILENO;
	}
	else if (table->i != ms->nbr_cmd_all - 1 && ms->nbr_cmd_all > 1)
	{
		dprintf(2, "ft_getfdout_2\n");
		table->fd_out = table->fd_pipe[1];
	}

	// table->nbr_infile = ft_cnt_infile(tb_lst);
	// if (table->nbr_infile || table->nbr_heredoc) // no infile
	// 	table->fd_in = ft_getfd_in(tb_lst);
	// else if (table->i != 0)
	// 	table->fd_in = table->fd_tmp;
	// table->nbr_outfile = ft_cnt_outfile(tb_lst);
	// if (table->nbr_outfile) // no outfile
	// 	table->fd_out = ft_getfd_out(tb_lst);
	// else if (table->i != ms->nbr_cmd_all - 1 && ms->nbr_cmd_all > 1)
	// 	table->fd_out = table->fd_pipe[1];
	dprintf(2 , "[%d] nbr_outfile:  %d fd_in_getfd__ :  %d\n", table->i, table->nbr_infile, table->fd_in);
	dprintf(2 , "[%d] nbr_outfile:  %d fd_out_getfd__ :  %d\n", table->i, table->nbr_outfile, table->fd_out);
}