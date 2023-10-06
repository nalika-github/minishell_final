/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtpcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 00:31:45 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/04 08:09:43 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
char	**ft_findpath(char **env)
{
	int		i;
	char	**path;

	i = -1;
	// while (env[++i])
	// 	dprintf(2, "env[%d] : %s\n", i, env[i]);
	// printf("findpath1\n");
	// exit(0);
	i = 0;
	while (1) // protect in case unset path
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' \
		&& env[i][2] == 'T' && env[i][3] == 'H')
			break;
		i++;
	}
	path = ft_split(env[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoinextra(path[i], "/" , BEFORE);
		i++;
	}
	return (path);
}

// void	ft_initvalue(t_data *data, char **env, char **av, int ac)
// {
// 	data->tmp_env = env;
// 	data->tmp_ac = ac;
// 	data->tmp_av = av;


// }

// void	ft_addcmd(int ac, char **av, t_data *data)
// {
// 	int	i;

// 	i = 2;
// 	while (i < ac)
// 	{


// 	}
// }

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	t_minishell main;

// 	ft_initvalue(main.data, env, av, ac);
// 	// ft_findpath(&data);
// 	printf("mainexec\n");
// 	exit(0);
// 	ft_mainexec(&main, ac, av);

// }
