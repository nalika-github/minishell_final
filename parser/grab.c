/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:24:09 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:08 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	arg_logic(char *line)
{
	size_t	size;

	size = 0;
	while(!ft_isspace(line[size]) && !ft_ismetachar(line[size]) && line[size])
		size++;
	return(size);
}

static size_t	quote_logic(char *line)
{
	size_t	size;
	char	quote;

	quote = line[0];
	size = 1;
	while(line[size] && line[size] != quote)
		size++;
	if (line[size + 1])
	{
		while(!ft_isspace(line[size]) && line[size] && \
		!ft_ismetachar(line[size]))
			size++;
	}
	if(line[size] && !ft_ismetachar(line[size]))
		size++;
	return(size);
}

static size_t	metachar_logic(char *line)
{
	char	meta_c;

	meta_c = line[0];
	if (line[1] != meta_c)
		return (1);
	else if (line[1] == meta_c)
		return (2);
	return (0);
}

static char	*grab_n_slide(char **line, size_t (*logic)(char *))
{
	size_t	size;
	char	*str;

	size = logic(*line);
	if (size > 0)
		str = ft_substr(*line, 0, size);
	while(size > 0)
	{
		(*line)++;
		size--;
	}
	while(ft_isspace(*(*line)))
		(*line)++;
	return (str);
}

void	grab_to_lst(t_list **lst, char **line, int index)
{
	t_list	*new;
	t_token	*token;

	new = ft_lstnew(malloc(sizeof(t_token)));
	token = new->data;
	if (index == 0)
		token->str = grab_n_slide(line, &arg_logic);
	if (index == 1)
		token->str = grab_n_slide(line, &arg_logic);
	if (index == 2)
		token->str = grab_n_slide(line, &quote_logic);
	if (index == 3)
		token->str = grab_n_slide(line, &metachar_logic);
	if ((*lst) == NULL)
		(*lst) = new;
	else
		ft_lstadd_back(lst, new);
}
