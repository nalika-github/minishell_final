/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:50:46 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:15 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	print_error_exit(t_minishell *ms, char *line)
{
	t_list	*tk_lst;

	if (ms->err_code == 1)
		dprintf(2, "%s", ERRINITCMDLST);
	if (ms->err_code == 2)
		dprintf(2, "%s", ERRQUOTEVALIDATE);
	if (ms->err_code == 3)
		dprintf(2, "%s", ERRTOKENIZE);
	if (ms->err_code == 4)
		dprintf(2, "%s", ERRSCHARVALIDATE);
	tk_lst = ms->tk_lst;
	free(line);
	ft_lstclear(&tk_lst, &free);
	ms->tk_lst = NULL;
	return (1);
}

static int special_char_validate(t_minishell *ms)
{
	t_list	*tk_lst;
	t_token	*token;

	tk_lst = ms->tk_lst;
	tk_lst = ft_lstlast(tk_lst);
	token = ((t_token *)(tk_lst->data));
	if(token->type == HEREDOC || token->type == INFILE || \
	token->type == APPEND || token->type == OUTFILE || token->type == PIPE)
		return (exit_err(ms, 4));
	return (0);
}

int	lexer(char *line, t_minishell *ms)
{
	if (init_command_list(&ms, line))
		return (print_error_exit(ms, line));
	if (quotes_validate(ms))
		return (print_error_exit(ms, line));
	if (tokenize(&ms))
		return (print_error_exit(ms, line));
	if (special_char_validate(ms))
		return (print_error_exit(ms, line));
	free(line);
	return (0);
}
