/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:33:01 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/04 02:17:48 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

long long	ft_atol_exit(char *str)
{
	long long	i;
	long long	sign;
	long long	n;

	n = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i++] - '0');
		if (((n >= 9223372036854775807) && (sign < 0)) \
		|| ((n > 9223372036854775807) && (sign < 0)))
			return (0);
	}
	return (n * sign);
}

int	ft_checknbr_exit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_exit(char **cmd, t_dict *dict)
{
	int					i;
	unsigned long long	nbr;
	int					len;

	i = 1;
	(void)dict; // don't forget free dict
	len = ft_cntstr(cmd) - 1;
	nbr = ft_atol_exit(cmd[1]);
	if (nbr <= 9223372036854775807 && len == 1)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit (EXIT_FAILURE);
	}
	else if (i == 1 && ft_checknbr_exit(cmd[1]) == EXIT_SUCCESS && nbr != 0)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		ft_putstr_fd("minishell: exit: too many arguments\n", STDOUT_FILENO);
		exit (EXIT_FAILURE);
	}
	else if (ft_checknbr_exit(cmd[1]) == EXIT_FAILURE || nbr == 0)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		ft_putstr_fd("minishell: exit: ", STDOUT_FILENO);
		ft_putstr_fd(cmd[1], STDOUT_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDOUT_FILENO);
		exit (EXIT_FAILURE);
	}
}
