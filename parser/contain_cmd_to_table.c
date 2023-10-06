/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_cmd_to_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:26:29 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 02:30:38 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static int ft_isrdr(int	type)
// {
// 	if(type == INFILE || type == OUTFILE)
// 		return (1);
// 	if(type == HEREDOC || type == APPEND)
// 		return (1);
// 	return (0);
// }

// static void next_cmd(t_table **table, int *i)
// {
// 	*table = (*table)->next;
// 	*i = 0;
// }

// static void grap_rdr_to_table(t_table **table, t_list **lst)
// {
// 	(*table)->rdr->type = type;
// 	*lst = (*lst)->next
// 	(*table)->rdr->file = ft_strdup((t_token*)((*lst)->data)->str);
// }

// static void grap_cmd_to_table(t_table **table, int *i)
// {
// 	((*table)->cmd)[*i] = ft_strdup((t_token*)((*lst)->data)->str);
// 	(*i)++;
// }

// static int	token_size(t_list *lst, int type)
// {
// 	int		i;
// 	t_token	*token;

// 	i = 0;
// 	while(lst)
// 	{
// 		token = lst->data;
// 		if (token->type == type)
// 			i++;
// 		lst = lst->next;
// 	}
// 	return(i);
// }

// int	contain_cmd_to_table(t_minishell **ms)
// {
// 	t_list	*lst;
// 	t_table	*table;
// 	int		type;
// 	int		i;

// 	lst = (*ms)->lst;
// 	table = (*ms)->table;
// 	i = 0;
// 	while(lst)
// 	{
// 		(*ms)->n = token_size(lst, CMD) + token_size(lst, ARG);
// 		table->cmd = malloc(((*ms)->n + 1) * sizeof(char *));
// 		type = ((t_token*)(lst->data))->type;
// 		if(type == CMD || type == ARG)
// 			grap_cmd_to_table(&table, &i);
// 		else if(ft_isrdr(type))
// 			grap_rdr_to_table(&table, &lst);
// 		if(type == PIPE)
// 			next_cmd(&table, &i);
// 		if (lst->next)
// 			lst = lst->next;
// 	}
// 	return (0);
// }
