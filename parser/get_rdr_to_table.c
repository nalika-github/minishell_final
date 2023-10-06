/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rdr_to_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:24:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:06 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	get_rdr_n_slide(t_list **rdr_lst, t_list **lst)
{
	t_token *token;
	t_rdr	*rdr;
	int		i;

	i = 0;
	token = (*lst)->data;
	while (*lst && token->type != PIPE)
	{
		token = (*lst)->data;
		if (token->type == INFILE || token->type == OUTFILE || \
		token->type == HEREDOC || token->type == APPEND)
		{
			if(i == 0)
				*rdr_lst = ft_lstnew(malloc(sizeof(t_rdr)));
			else
				ft_lstadd_back(rdr_lst, ft_lstnew(malloc(sizeof(t_rdr))));
			rdr = (ft_lstlast(*rdr_lst))->data;
			rdr->type = token->type;
			*lst = (*lst)->next;
			token = (*lst)->data;
			rdr->file = ft_strdup(token->str);
			i = 1;
		}
		*lst = (*lst)->next;
	}
	if (*lst)
		token = (*lst)->data;
	if (token->type == PIPE)
		*lst = (*lst)->next;
}

int	get_rdr_to_table(t_minishell **ms)
{
	t_list	*tb_lst;
	t_list	*tk_lst;

	if (!(*ms))
		return (exit_err(*ms, 7));
	tb_lst = (*ms)->tb_lst;
	tk_lst = (*ms)->tk_lst;
	while(tb_lst)
	{
		get_rdr_n_slide(&(((t_table *)(tb_lst->data))->rdr), &tk_lst);
		tb_lst = tb_lst->next;
	}
	return (0);
}
