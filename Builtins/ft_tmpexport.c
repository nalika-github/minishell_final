/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmpexport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:04 by nkietwee          #+#    #+#             */
/*   Updated: 2023/09/17 02:10:20 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//str is arg that wanted to add at last arg from env
t_dict_value **ft_get_value(char **str)
{
	int	len;
	t_dict_value **tmp;
	char	**tmp_str;
	int	i;
	int	j;

	len = ft_cntstr(str);
	i = 0;
	j = 1;
	tmp = malloc(sizeof(t_dict_value *) * (len + 1));
	if (!tmp)
		return (NULL);
	while (j < len)
	{
		// printf("Hello\n");
		tmp[i] = malloc(sizeof(t_dict_value));
		tmp_str = ft_split(str[j], '=');
		if (tmp_str[0])
			tmp[i]->key = ft_strdup(tmp_str[0]);
		else
			tmp[i]->key = ft_strdup("");
		if (tmp_str[1])
			tmp[i]->value = ft_strdup(tmp_str[1]);
		else
			tmp[i]->value = NULL;
		i++;
		j++;
	}
	return (tmp);
}
/*av instead value that it want to attach with last arg*/
t_dict	*ft_exports(char **env, char **av)
{
	t_dict			*dict;
	t_dict			*tmp_newdict;
	t_dict_value	**tmp_value;
	int	i;
	int	len;

	i = 0;
	printf("ft_lstadd_insert\n");
	dict = ft_getenv(env);
	tmp_value =  ft_get_value(av);
	// ft_prtdict_value(tmp_value);
	len = ft_cntdict_export(tmp_value);
	while (i < len)
	{
		tmp_newdict = ft_lstnew_dict(tmp_value[i]);
		ft_lstadd_back_dict(&dict, tmp_newdict);
		i++;
	}
	ft_prtdict(dict);
	return (tmp_newdict); // for print env
}



