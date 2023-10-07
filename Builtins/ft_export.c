/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:48:06 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 21:14:46 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_swap(t_dict **dict)
{
		char *tmp_key=NULL;
		char *tmp_value=NULL;

		tmp_key = (*dict)->next->tmp_dict->key;
		tmp_value = (*dict)->next->tmp_dict->value;

		(*dict)->next->tmp_dict->key = (*dict)->tmp_dict->key;
		(*dict)->next->tmp_dict->value = (*dict)->tmp_dict->value;

		(*dict)->tmp_dict->key = tmp_key;
		(*dict)->tmp_dict->value = tmp_value;

}

void	ft_lstascend(t_dict *dict)
{
	int	len;
	t_dict *head;
	t_dict *head2;
	int	i;
	int size;


	i = 0;
	len = ft_lstsize_dict(dict);
	size = ft_lstsize_dict(dict);
	head2 = dict; // for print
	head = dict;
	while (i < size - 1)
	{
		dict = head;
		while (dict && (dict)->next != NULL)
		{
			if (ft_strcmp((dict)->tmp_dict->key , (dict)->next->tmp_dict->key) > 0)
				ft_swap(&dict);
			else
				(dict) = (dict)->next ;
		}
		i++;
	}
	ft_prtexport(head2);
	//freeloop
}

/* check first character of variable(key) */
void	ft_checkname(char **cmd)
{
	int	i;

	i = 1; // i = 0 is export
	while (cmd[i])
	{
		if (ft_isalpha(cmd[i][0]) == EXIT_FAILURE)
		{
			ft_putstr_fd("bash: export: `", STDERR_FILENO);
			ft_putstr_fd(cmd[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDOUT_FILENO);
		}
		i++;
	}
	// ft_exit()
}


//return t_dict for print env
void	ft_export(char **cmd, t_dict *dict)
{
	int	len;
	t_dict *tmp_export=NULL;

	ft_checkname(cmd); //check first character of variable(key)
	len = ft_cntstr(cmd);
	if (len == 1) // (export no arg)
		ft_lstascend(dict);
		// ft_printvalue_ep(env);
	if (len > 1) // (export with arg)
		ft_addvalueexport(cmd, dict); // left assign value
}