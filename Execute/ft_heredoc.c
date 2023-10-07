/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:36:27 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 20:32:49 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_prt_type(int type)
{
	if (type == EMPTY)
		dprintf(2, "EMPTY\n");
	else if (type == CMD)
		printf("CMD\n");
	else if (type == ARG)
		printf("ARG\n");
	else if (type == FPATH)
		printf("FPATH\n");
	else if (type == INFILE)
		dprintf(2, "INFILE\n");
	else if (type == OUTFILE)
		dprintf(2, "OUTFILE\n");
	else if (type == HEREDOC)
		dprintf(2, "HEREDOC\n");
	else if (type == PIPE)
		printf("PIPE\n");
	else if (type == APPEND)
		printf("APPEND\n");

}
void	ft_prt_heredoc(t_list *tb_list)
{
	t_table *table;
	t_rdr	*rdr;
	t_list *rdr_lst;

	// printf("Entry ft_prt_heredoc\n");
	while (tb_list)
	{
		table = (t_table *)(tb_list->data);
		rdr_lst = table->rdr;
		while (rdr_lst)
		{
			rdr = (t_rdr *)(rdr_lst->data);
			if (rdr->type == HEREDOC)
			{
				// ft_prt_type(rdr->type);
				printf("heredoc__ : %s\n", rdr->file);
			}
			rdr_lst = rdr_lst->next;
		}
		tb_list = tb_list->next;
	}
}

// int	ft_do_here(t_list *rdr_lst, int nbr_heredoc, char *file)
// {
// 	t_table *table;
// 	// t_list	*rdr_lst;
// 	t_rdr	*rdr;
// 	char	*tmp;
// 	int		fd_heredoc;
// 	int		i;

// 	i = 0;
// 	// ft_prt_heredoc(tb_lst);
// 	fd_heredoc = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	if (fd_heredoc == -1)
// 		return (-1);
// 	while (rdr_lst)
// 	{
// 		rdr = (t_rdr *)(rdr_lst->data);
// 		if (rdr->type == HEREDOC)
// 		{
// 			rdr->file = ft_strjoinextra(rdr->file, "\n", NONE);
// 			while (rdr->type == HEREDOC)
// 			{
// 				write(STDOUT_FILENO, "> ", 2);
// 				tmp = get_next_line(STDIN_FILENO);
// 				if (ft_strcmp(tmp, rdr->file) == EXIT_SUCCESS)
// 				{
// 					i++;
// 					break;
// 				}
// 				if (i == nbr_heredoc - 1)
// 					write(fd_heredoc, tmp, ft_strlen(tmp));
// 			}
// 		}
// 		rdr_lst = rdr_lst->next;
// 		// dprintf(2, "lst : %s\n", ((t_rdr *)(rdr_lst->data))->file );
// 	}
// 	close (fd_heredoc);
// 	fd_heredoc = open(file, O_RDONLY , 0644);
// 	// exit(0);
// 	return (fd_heredoc);
// }

// char	*ft_createfile(int round)
// {
// 	int fd;
// 	char *file;

// 	char *str = ft_itoa(round);
// 	// dprintf(2, "str : %s\n" ,str);
// 	file = ft_strjoin("../tmpfile_", str);
// 	free (str);
// 	return(file);
// }

// int	ft_main_heredoc(t_list *tb_lst)
// {
// 	t_table *table;
// 	t_data	*exec_data;
// 	int		round;
// 	char	*file;

// 	round = 0;
// 	while (tb_lst)
// 	{
// 		table = (t_table *)(tb_lst->data);
// 		exec_data = (t_data *)(&(table->exec_data));
// 		exec_data->nbr_heredoc = ft_cnt_heredoc(tb_lst);
// 		exec_data->file = ft_createfile(round);
// 		dprintf(2, "nbr_heredoc : %d\n", exec_data->nbr_heredoc);
// 		dprintf(2, "file : %s\n", exec_data->file);
// 		exec_data->fd_heredoc = ft_do_here(table->rdr, exec_data->nbr_heredoc, file);
// 		dprintf(2, "fd_heredoc_main[%d] : %d\n", round, exec_data->fd_heredoc);
// 		// free(exec_data->file);
// 		round++;
// 		tb_lst = tb_lst->next;
// 	}
// 	dprintf(2, "End\n");
// 	return (0);
// }


void	ft_heredoc(t_list *tb_lst)
{
	t_table *table;
	t_list	*rdr_lst;
	t_rdr	*rdr;
	char	*tmp;

	while (tb_lst)
	{
		table = (t_table *)(tb_lst->data);
		rdr_lst = table->rdr;
		while (rdr_lst)
		{
			rdr = (t_rdr *)(rdr_lst->data);
			if (rdr->type == HEREDOC)
			{
				rdr->file = ft_strjoinextra(rdr->file, "\n", NONE);
				table->fd_heredoc = open(rdr->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
				dprintf(2, "rdr->file : %s\n" , rdr->file);
				write(STDOUT_FILENO, "> ", 2);
				tmp = get_next_line(STDIN_FILENO);
				while (tmp)
				{
					if (ft_strcmp(tmp, rdr->file) == EXIT_SUCCESS)
						break;
					write(table->fd_heredoc, tmp, ft_strlen(tmp));
					if (tmp)
						free(tmp);
					write(STDOUT_FILENO, "> ", 2);
					tmp = get_next_line(STDIN_FILENO);
				}
				close (table->fd_heredoc);
				dprintf(2,"r->file = %s t->fd_heredoc = %d\n", rdr->file, table->fd_heredoc);
			}
			rdr_lst = rdr_lst->next;
			// dprintf(2, "lst : %s\n", ((t_rdr *)(rdr_lst->data))->file );
		}
		dprintf(2,"table->fd_heredoc = %d\n", table->fd_heredoc);
		tb_lst = tb_lst->next;
	}
}

// int	ft_heredoc(t_list *tb_lst, int nbr_heredoc)
// {
// 	t_table *table;
// 	t_list	*rdr_lst;
// 	t_rdr	*rdr;
// 	char	*tmp;
// 	int		fd_heredoc;
// 	int		i;

// 	i = 0;
// 	// ft_prt_heredoc(tb_lst);
// 	fd_heredoc = open("../tmpfile", O_CREAT | O_RDWR | O_TRUNC, 0644);
// 	// printf("fd_heredoc : %d\n", fd_heredoc);
// 	while (tb_lst)
// 	{
// 		table = (t_table *)(tb_lst->data);
// 		rdr_lst = table->rdr;
// 		while (rdr_lst)
// 		{
// 			rdr = (t_rdr *)(rdr_lst->data);
// 			if (rdr->type == HEREDOC)
// 				rdr->file = ft_strjoinextra(rdr->file, "\n", NONE);
// 			else
// 				break;
// 			while (1)
// 			{
// 				write(STDOUT_FILENO, "> ", 2);
// 				tmp = get_next_line(STDIN_FILENO);
// 				if (ft_strcmp(tmp, rdr->file) == EXIT_SUCCESS)
// 				{
// 					// dprintf(2, "hello\n");
// 					i++;
// 					break;
// 				}
// 				if (i == nbr_heredoc - 1)
// 					write(fd_heredoc, tmp, ft_strlen(tmp));
// 			}
// 			rdr_lst = rdr_lst->next;
// 			// dprintf(2, "lst : %s\n", ((t_rdr *)(rdr_lst->data))->file );
// 		}
// 		tb_lst = tb_lst->next;
// 	}
// 	close (fd_heredoc);
// 	fd_heredoc = open("../tmpfile", O_RDONLY , 0644);
// 	return (fd_heredoc);
// }

// // int main(int ac, char **av)
// // {
// // 	// t_data data;
// // 	ft_heredoc(ac, av);
// // }