/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:59:48 by ptungbun          #+#    #+#             */
/*   Updated: 2023/09/17 01:33:58 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*room;

	room = (void *)malloc(nmemb * size);
	if (!room)
		return (0);
	ft_bzero(room, nmemb * size);
	return (room);
}
