/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:07:52 by nkietwee          #+#    #+#             */
/*   Updated: 2023/06/26 00:06:53 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void    ft_prterr(int mode, char *cmd, char *str, int err)
{
    
    if (mode == PER_DN)
        printf("bash: %s: %s: No such file or directory" ,cmd, str);
    else if (mode == CANNT_OPEN)
        printf("bash: %s: %s: Permission denied" ,cmd, str);
    exit (errno); // ??
}