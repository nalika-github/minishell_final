/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <ptungbun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:24:48 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/08 20:43:24 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Common Header  */
# include "libft.h"
# include "libminishell.h"

typedef struct  s_minishell t_minishell;
typedef struct  s_list t_list;
typedef struct  s_token t_token;

/*  prompt.c  */

char	*prompt(void);

/*  main.c  */

void clear_tb_n_tk(t_minishell *ms);

/*  lexer.c  */

int		lexer(char *line, t_minishell *env);


/*  init_command_list.c  */

int		init_command_list(t_minishell **env, char *line);

/*  grab.c  */

void	grab_to_lst(t_list **lst, char **line, int index);

/*  tokenize  */

int	tokenize(t_minishell **env);

/*  quotes_validate.c  */

int	quotes_validate(t_minishell *env);

/*  paser.c  */

int	paser(t_minishell *ms);

/*  get_cmd_to_table.c  */

int	get_cmd_to_table(t_minishell **ms);

/*  get_rdr_to_table.c  */

int	get_rdr_to_table(t_minishell **ms);

/*  scan_n_expand.c  */

void	scan_n_expand(t_list **ep_lst, t_dict *dict, char *exit_code);
void	expand(char **ep_str, t_dict *dict, char *exit_code);

/*  expand_var.c  */

int	expand_var(t_minishell **ms);
// void	ep_lst_to_str(t_token **token, t_list **ep_lst);
// void	quotes_remove(t_list **ep_lst);

/*  expand_in_quote  */

void	expand_in_quote(char **ep_str, t_dict *dict, char *exit_code);

/*  exit_err.c  */

int	exit_err(t_minishell *ms, int index);

#endif