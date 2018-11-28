/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:36:44 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 10:23:39 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			counter1;

	counter1 = 0;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (counter1 < n)
	{
		pdest[counter1] = psrc[counter1];
		if (psrc[counter1] == (unsigned char)c)
			return (pdest + counter1 + 1);
		counter1++;
	}
	return (NULL);
}
