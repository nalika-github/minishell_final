/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:26:21 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:29 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isvalide_quote(char *str)
{
	int		quote_open;
	int		i;
	char	quote;

	quote_open = 0;
	i = 0;
	while(str[i])
	{
		if (quote_open == 0 && (str[i] == '\'' || str[i] == '\"'))
		{
			quote_open = 1;
			quote = str[i];
		}
		else if (quote_open == 1 && (str[i] == quote))
			quote_open = 0;
		i++;
	}
	if (quote_open == 1)
		return (0);
	return (1);
}

int	quotes_validate(t_minishell *ms)
{
	t_list	*tk_lst;
	char	*str;

	tk_lst = ms->tk_lst;
	while (tk_lst)
	{
		str = ((t_token *)(tk_lst->data))->str;
		if (ft_isquote(*str))
		{
			if (!ft_isvalide_quote(str))
				return (exit_err(ms, 2));
		}
		tk_lst = tk_lst->next;
	}
	 return (0);
}
