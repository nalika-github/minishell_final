/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:36:50 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:33:27 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*strjoin_to_ret(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin("\e[1;32m", s1);
	tmp = ft_strjoin(str, " ");
	free(str);
	str = ft_strjoin(tmp, "\e[0;35m");
	free(tmp);
	tmp = ft_strjoin(str, s2);
	free(str);
	str = ft_strjoin(tmp, " \e[1;34m$ \e[0;0m");
	free(tmp);
	return (str);
}

char	*prompt(void)
{
	char	**cwd_split;
	char	*cwd;
	char	*usr;
	char	*ret;
	int		i;

	cwd_split = ft_split(getcwd(NULL, 0), '/');
	i = 0;
	while(cwd_split[i])
		i++;
	cwd = cwd_split[i - 1];
	usr = getenv("USER");
	if (usr == NULL)
		usr = "";
	i = 0;
	ret = strjoin_to_ret(usr, cwd);
	while(cwd_split[i])
	{
		free(cwd_split[i]);
		i++;
	}
	free(cwd_split);
	return (ret);
}
