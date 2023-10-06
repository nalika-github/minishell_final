/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:25:59 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:01 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	size_logic(char *tk_str, int index)
{
	size_t	i;
	char	quote;

	i = 0;
	if (index == 0)
	{
		if (tk_str[i] == '$' && tk_str[i + 1] == '?')
			return(2);
		if(tk_str[i] == '$')
			i++;
		while(tk_str[i] && !ft_isquote(tk_str[i]) && tk_str[i] != '$')
			i++;
		return (i);
	}
	if (index == 1)
	{
		quote = tk_str[i];
		i++;
		while(tk_str[i] && tk_str[i] != quote)
			i++;
		if (tk_str[i] == quote)
			i++;
		return (i);
	}
	return (-1);
}

static t_list	*init_expand_lst(char *tk_str)
{
	size_t	size;
	t_list	*ep_lst;
	int		index;

	ep_lst = NULL;
	while(*tk_str)
	{
		index = 0;
		if (ft_isquote(*tk_str))
			index = 1;
		size = size_logic(tk_str, index);
		if(!ep_lst)
			ep_lst = ft_lstnew(ft_substr(tk_str, 0, size));
		else
			ft_lstadd_back(&ep_lst, ft_lstnew(ft_substr(tk_str, 0, size)));
		while(size > 0)
		{
			(tk_str)++;
			size--;
		}
	}
	return (ep_lst);
}

void	quotes_remove(t_list **ep_lst)
{
	char	*ep_str;
	t_list	*ep_lst_ptr;

	ep_lst_ptr = *ep_lst;
	while(ep_lst_ptr)
	{
		ep_str = ft_strdup(ep_lst_ptr->data);
		if (*ep_str == '\'' || *ep_str == '\"')
		{
			free(ep_lst_ptr->data);
			(ep_lst_ptr->data) = ft_substr(ep_str, 1, ft_strlen(ep_str) - 2);
			free(ep_str);
		}
		ep_lst_ptr = ep_lst_ptr->next;
	}
}

static void	ep_lst_to_str(t_token **token, t_list **ep_lst)
{
	char	*str;
	char	*tmp;
	t_list	*ep_lst_ptr;

	ep_lst_ptr = *ep_lst;
	str = ft_strdup("");
	while(ep_lst_ptr)
	{
		tmp = ft_strjoin(str, (char *)(ep_lst_ptr->data));
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		ep_lst_ptr = ep_lst_ptr->next;
	}
	free((*token)->str);
	(*token)->str = str;
}

int	expand_var(t_minishell **ms)
{
	t_list	*tk_lst;
	t_token	*token;
	t_dict	*dict;
	t_list	*ep_lst;
	char	*exit_code;

	tk_lst = (*ms)->tk_lst;
	dict = (*ms)->dict;
	exit_code = ft_itoa((*ms)->exit_code);
	if (!exit_code)
		return (exit_err(*ms, 5));
	while (tk_lst)
	{
		token = tk_lst->data;
		ep_lst = init_expand_lst(token->str);
		scan_n_expand(&ep_lst, dict, exit_code);
		quotes_remove(&ep_lst);
		ep_lst_to_str(&token, &ep_lst);
		ft_lstclear(&ep_lst, &free);
		tk_lst = tk_lst->next;
	}
	free(exit_code);
	return (0);
}
