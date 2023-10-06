/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:50:33 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/17 02:28:33 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// t_dict	**ft_getnewenv(t_dict **old_dict, char **env)
// {
// 	int	i;
// 	int	len;
// 	char **tmp_env;
// 	t_dict	**dict;
// 	char *tmp_pwd;

// 	// if (old_dict)
// 	// 	ft_freedict(old_dict);
// 	i = 0;
// 	len = ft_cntline(env);
// 	dict = malloc(sizeof(t_dict *) * (len + 1));
// 	if (!dict)
// 		return (0);
// 	while (i < len)
// 	{
// 		dict[i] = malloc(sizeof(t_dict));
// 		if (!dict[i])
// 			return (0);
// 		tmp_env = ft_split(env[i], '=');
// 		if (tmp_env[0])
// 			dict[i]->key = ft_strdup(tmp_env[0]);
// 		else
// 			dict[i]->key = NULL;
// 		if (tmp_env[1] && ft_findstr(tmp_env[0], "PWD", 3) == EXIT_SUCCESS)
// 		{
// 			tmp_pwd = getenv("PWD");
// 			dict[i]->value = ft_strdup(tmp_pwd);
// 		}
// 		else if (tmp_env[1])
// 			dict[i]->value = ft_strdup(tmp_env[1]);
// 		else
// 			dict[i]->value = "";
// 		i++;
// 	}
// 	dict[i] = NULL;
// 	return (dict);
// }

// t_dict	**ft_getenv(char **env)
// {
// 	int	i;
// 	int	len;
// 	char **tmp_env;
// 	t_dict	**dict;

// 	i = 0;
// 	len = ft_cntline(env);
// 	dict = malloc(sizeof(t_dict *) * (len + 1));
// 	if (!dict)
// 		return (0);
// 	while (i < len)
// 	{
// 		dict[i] = malloc(sizeof(t_dict));
// 		if (!dict[i])
// 			return (0);
// 		tmp_env = ft_split(env[i], '=');
// 		if (tmp_env[0])
// 			dict[i]->key = ft_strdup(tmp_env[0]);
// 		else
// 			dict[i]->key = "";
// 		if (tmp_env[1])
// 			dict[i]->value = ft_strdup(tmp_env[1]);
// 		else
// 			dict[i]->value = NULL;
// 		i++;
// 	}
// 	dict[i] = NULL;
// 	return (dict);
// }


t_dict_value **ft_getvalue_env(char **env)
{
	int	line_env;
	t_dict_value **tmp_dict;
	char	**tmp_env;
	int	i;

	line_env = ft_cntstr(env);
	// printf("line : %d\n", line_env);
	i = 0;
	tmp_dict = malloc(sizeof(t_dict_value *) * (line_env + 1));
	if (!tmp_dict)
		return (NULL);
	while (i < line_env)
	{
		tmp_dict[i] = malloc(sizeof(t_dict_value));
		tmp_env = ft_split(env[i], '=');
		if (tmp_env[0])
			tmp_dict[i]->key = ft_strdup(tmp_env[0]);
		else
			tmp_dict[i]->key = ft_strdup("");
		if (tmp_env[1])
			tmp_dict[i]->value = ft_strdup(tmp_env[1]);
		else
			tmp_dict[i]->value = NULL;
		i++;
	}
	return (tmp_dict);
}

// t_dict *ft_env_forexport(char **env)
t_dict *ft_getenv(char **env)
{
	int			i;
	int			len;
	t_dict_value	**tmp_env;
	t_dict *tmp;
	t_dict	*dict;

	i = 0;
	tmp_env = ft_getvalue_env(env);
	len = ft_cntstr(env); //fixed in case export value
	dict = NULL;
	while (i < len)
	{
		tmp = ft_lstnew_dict(tmp_env[i]);
		ft_lstadd_back_dict(&dict, tmp);
		i++;
	}
	// printf("size : %d\n" ,ft_lstsize(dic_export));
	return(dict);
}