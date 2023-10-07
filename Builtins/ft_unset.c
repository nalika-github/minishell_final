/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:14 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/07 18:04:28 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// t_dict	*ft_lstdelete_node(t_dict **dict, int index)
// {
// 	t_dict *head;
// 	t_dict *start;

// 	head = dict;
// 	start = dict;
// 	if (index == 0)
// 	{
// 		dict = dict->next;
// 		// return (dict);
// 	}
// 	else
// 	{
// 		while (index + 1 != 1) // fixed index == 0
// 		{
// 			start = dict;
// 			dict = dict -> next;
// 			index--;
// 		}
// 		start->next = dict->next;
// 		dict = head;
// 		return(dict);
// 	}
// 	// return (dict); //??
// 	// ft_prtdict(dict);
// }

// t_dict	*ft_lstdelete_node(t_dict **dict, int index)
void	ft_freenode(t_dict *dict, int index)
{
	int	i;

	i = 0;
	while (dict)
	{
		if (i == index)
		{
			free(dict->tmp_dict->key);
			free(dict->tmp_dict->value);
			free(dict->tmp_dict);
			free(dict);
			return ;
		}
		i++;
		dict = dict->next;
	}
}

void	ft_lstdelete_node(t_dict **dict, int index)
{
	t_dict *head;
	t_dict *start;
	t_dict *tmp;
	t_dict *tmp_2;
	t_dict *free_node;

	head = (*dict);
	start = (*dict);
	tmp_2 = (*dict);
	free_node = (*dict);
	// 	if (index == 0)
	// {
	// 	// free(&dict);
	// 	// dprintf(2, "delete_index0\n");
	// 	(*dict) = (*dict)->next;
	// 	ft_freenode(head, 0);
	// }
	if (index == 0)
	{
		// free(&dict);
		// dprintf(2, "delete_index0\n");

		(*dict) = (*dict)->next;
		free(head->tmp_dict->key);
		free(head->tmp_dict->value);
		free(head->tmp_dict);
		free(head);
		// ft_freenode(head, 0);
	}
	else
	{
		int	l = 0;
		while (l < index) // fixed index == 0
		{
			start = (*dict);
			(*dict) = (*dict)->next;
			free_node = free_node->next;
			l++;
		}
		dprintf(2, "l : %d\n", l);
		start->next = (*dict)->next;
		free(free_node->tmp_dict->key);
		free(free_node->tmp_dict->value);
		free(free_node->tmp_dict);
		free(free_node);
		(*dict) = head;
	}
	// dprintf(2, "dict_unset\n");
	// ft_prtdict(*dict);
}

int		ft_findkey_export(char *key, t_dict	*dict)
{
	int	i;

	i = 0;
	while (dict)
	{
		if (ft_strcmp(dict->tmp_dict->key, key) == 0)
			return (i);
		i++;
		dict = dict->next;
	}
	return (-1);
}

void	ft_unset(char **cmd, t_dict **dict)
{
	int		i;
	int		index;
	t_dict	*tmp;

	i = 1;
	dprintf(2, "ft_unset\n");
	dprintf(2, "cmd[0] : %s\n" , cmd[0]);
	dprintf(2, "cmd[0] : %s\n" , cmd[1]);
	while (cmd[i])
	{
		index = ft_findkey_export(cmd[i], *dict);
		dprintf(2, "ft_index : %d\n", index);
		if (index >= 0)
			ft_lstdelete_node(dict, index);
		i++;
	}
	// ft_prtdict(tmp);
}