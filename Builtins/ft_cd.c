/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:32:39 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/04 02:12:16 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_isrepeat(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict)
	{
		if(ft_strcmp(dict->tmp_dict->key , key) == 0)
			return (i);
		dict = dict->next;
		i++;
	}
	return (-1);
}
void	ft_update_env(char *old_pwd, t_dict *dict)
{
	t_dict	*newdict;
	int		index;

	index = ft_isrepeat("OLDPWD" , dict);
	if (index >= 0)
	{
		while (index > 0)
		{
			index--;
			dict = dict->next;
		}
		free(dict->tmp_dict->value);
		dict->tmp_dict->value = ft_strdup(old_pwd);
		return ;
	}
	newdict = ft_lstnew_dict(malloc(sizeof(t_dict_value)));
	newdict->tmp_dict->key = ft_strdup("OLDPWD");
	newdict->tmp_dict->value = ft_strdup(old_pwd);
	ft_lstadd_back_dict(&dict, newdict);
}
void	ft_cd(char **cmd, t_dict *dict)
{
	char	pre_path[128];
	char	*tmp;
	char	*old_pwd;
	int		errno;

	errno = 0;
	// dprintf(2, "old_pwd : %s\n", old_pwd);
	// old_pwd = NULL;
	old_pwd = getcwd(NULL, 0);
	ft_update_env(old_pwd, dict);
	if (cmd[1] == NULL || ft_findstr(cmd[1], "~", 1) == EXIT_SUCCESS)
		cmd[1] = getenv("HOME");
	// if (ft_strcmp(cmd[1], "-") == 0) // left test
	// {
	// 	dprintf(2, "c1\n");
	// 	if (!old_pwd)
	// 	{
	// 		ft_putstr_fd("bash: cd: OLDPWD not set", EXIT_FAILURE);
	// 		return ;
	// 	}
	// 	dprintf(2, "c2\n");
	// 	chdir(old_pwd);
	// 	dprintf(2, "c3\n");
	// }
	if (access(cmd[1], F_OK) == 0)
	{
		if (access(cmd[1], R_OK | F_OK) == 0)
			chdir(cmd[1]);
		else
			ft_prterr_builtins(CANNT_OPEN, "cd", cmd[1], errno);
	}
	else
		ft_prterr_builtins(PER_DN, "cd",cmd[1], errno);
}