/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:09:56 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 09:56:47 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		counter1;
	char	*pdest;
	char	*psrc;

	counter1 = 0;
	pdest = (char *)dest;
	psrc = (char *)src;
	while (counter1 < (int)n)
	{
		pdest[counter1] = psrc[counter1];
		counter1++;
	}
	return ((void *)pdest);
}
