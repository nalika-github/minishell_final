/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:32:48 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:32:56 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	print_lst(t_list *ep_lst_again)
// {
// 	char	*ep_str_again;

// 	while (ep_lst_again)
// 	{
// 		ep_str_again = ep_lst_again->data;
// 		printf("ep_str_again = %s\n", ep_str_again);
// 		ep_lst_again = ep_lst_again->next;
// 	}
// }

static size_t	size_logic(char *ep_str)
{
	size_t	size;

	size = 0;
	if (ep_str[size] != '$')
	{
		while(ep_str[size] != '$' && ep_str[size])
			size++;
		return (size);
	}
	if (ep_str[size] == '$' && ep_str[size + 1] == '?')
		return (2);
	while (ep_str[size] && !ft_isquote(ep_str[size]))
		size++;
	return (size);
}

static t_list	*init_ep_lst_again(char *ep_str)
{
	size_t	size;
	t_list	*ep_lst_again;

	ep_lst_again = NULL;
	while(*ep_str)
	{
		size = size_logic(ep_str);
		if(!ep_lst_again)
			ep_lst_again = ft_lstnew(ft_substr(ep_str, 0, size));
		else
			ft_lstadd_back(&ep_lst_again, ft_lstnew(ft_substr(ep_str, 0, size)));
		while(size > 0)
		{
			ep_str++;
			size--;
		}
	}
	return (ep_lst_again);
}

char	*ep_lst_again_to_str(t_list *ep_lst_again)
{
	char	*str;
	char	*tmp;

	str = ft_strdup("");
	while(ep_lst_again)
	{
		tmp = ft_strjoin(str, (char *)ep_lst_again->data);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		ep_lst_again = ep_lst_again->next;
	}
	return (str);
}

void	expand_in_quote(char **ep_str, t_dict *dict, char *exit_code)
{
	t_list	*ep_lst_again;
	t_list	*ep_lst_again_ptr;
	char	*ep_str_again;

	ep_lst_again = init_ep_lst_again(*ep_str);
	ep_lst_again_ptr = ep_lst_again;
	while(ep_lst_again)
	{
		ep_str_again = ((char *)(ep_lst_again->data));
		if (*ep_str_again == '$')
		{
			expand(&ep_str_again, dict, exit_code);
			ep_lst_again->data = ep_str_again;
		}
		ep_lst_again = ep_lst_again->next;
	}
	// print_lst(ep_lst_again_ptr);
	free(*ep_str);
	*ep_str = ep_lst_again_to_str(ep_lst_again_ptr);
	ft_lstclear(&ep_lst_again_ptr, &free);
}
