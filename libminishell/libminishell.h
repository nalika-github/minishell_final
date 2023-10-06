/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:45:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/28 23:21:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_dict_value
{
	char *key;
	char *value;
} t_dict_value;

typedef struct s_dict
{
	t_dict_value *tmp_dict;
	struct s_dict *next;
} t_dict;

/*  libft_minisell  */

int		ft_ismetachar(char c);
int		ft_isquote(char c);
int		ft_isvalide_quote(char *str);
void	ft_lstadd_front_dict(t_dict **lst, t_dict *new);
void	ft_lstadd_back_dict(t_dict **lst, t_dict *new);
t_dict	*ft_lstnew_dict(void *content);

#endif
