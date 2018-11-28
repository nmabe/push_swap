/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:37:30 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:04:56 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem1;

	if (!(mem1 = (void *)malloc(sizeof(mem1) * (size))) || !size)
		return (NULL);
	mem1 = ft_memset(mem1, 0, size);
	return (mem1);
}
