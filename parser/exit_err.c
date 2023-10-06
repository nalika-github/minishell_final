/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:42:33 by ptungbun          #+#    #+#             */
/*   Updated: 2023/10/02 21:32:52 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	set_exit_code(t_minishell *ms)
{
	if (ms->err_code == 1 || ms->err_code == 2 || \
	ms->err_code == 4 || ms->err_code == 5 || \
	ms->err_code == 7)
		ms->exit_code = 128;
	if (ms->err_code == 3)
		ms->exit_code = 1;
}

int	exit_err(t_minishell *ms, int index)
{
	ms->err_code = index;
	set_exit_code(ms);
	return (ms->err_code);
}
