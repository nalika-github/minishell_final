/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:59:50 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:34 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	search_start(char *str, int *index)
{
	if (ft_ismetachar(str[0]))
	{
		*index = 0;
		if (str[0] == '|')
			return (PIPE);
		if (str[0] == '>' && str[1] == '>')
			return (APPEND);
		if (str[0] == '>')
			return (OUTFILE);
		if (str[0] == '<' && str[1] == '<')
			return (HEREDOC);
		if (str[0] == '<')
			return (INFILE);
	}
	*index = 1;
	return (CMD);
}

static int	search_empty(char *str, int *index)
{
	int	i;

	i = 0;
	if (str[i] == '\'' || str[i] == '\"')
		i++;
	if (ft_ismetachar(str[i]))
	{
		if (str[i] == '|')
			return (PIPE);
		if (str[i] == '>' && str[i + 1] == '>')
			return (APPEND);
		if (str[i] == '>')
			return (OUTFILE);
		if (str[i] == '<' && str[i + 1] == '<')
			return (HEREDOC);
		if (str[i] == '<')
			return (INFILE);
	}
	if (*index == 0)
	{
		*index = 1;
		return (CMD);
	}
	return (ARG);
}

static int	tag_token(int *tag_ctrl)
{
	int	temp;

	if (*tag_ctrl == CMD)
	{
		*tag_ctrl = EMPTY;
		return (CMD);
	}
	else if (*tag_ctrl == ARG)
	{
		*tag_ctrl = EMPTY;
		return (ARG);
	}
	else if (*tag_ctrl == HEREDOC || *tag_ctrl == INFILE \
	|| *tag_ctrl == OUTFILE || *tag_ctrl == APPEND)
	{
		temp = *tag_ctrl;
		*tag_ctrl = FPATH;
		return (temp);
	}
	else if (*tag_ctrl == PIPE)
	{
		*tag_ctrl = EMPTY;
		return (PIPE);
	}
	else if (*tag_ctrl == FPATH)
	{
		*tag_ctrl = EMPTY;
		return (FPATH);
	}
	return (0);
}

int	tokenize(t_minishell **ms)
{
	t_list	*tk_lst;
	int		tag_ctrl;

	if(!ms)
		return(exit_err(*ms, 3));
	tk_lst = (*ms)->tk_lst;
	tag_ctrl = EMPTY;
	(*ms)->index = -1;
	while(tk_lst)
	{
		if ((*ms)->index == -1)
			tag_ctrl = search_start(((t_token *)tk_lst->data)->str, &(*ms)->index);
		else if (tag_ctrl == EMPTY)
			tag_ctrl = search_empty(((t_token *)tk_lst->data)->str, &(*ms)->index);
		if (tag_ctrl == PIPE)
			(*ms)->index = -1;
		((t_token *)tk_lst->data)->type = tag_token(&tag_ctrl);
		tk_lst = tk_lst->next;
	}
	return(0);
}
